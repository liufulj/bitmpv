#include "stdafx.h"
#include"PlayerForCS.h"
#include "WinPlayer.h"
#include <thread>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include <SDL.h>
#include "client.h"
#include "render_gl.h"
}
#include"CJsonObject.hpp"
#include<list>
#include"CJsonHelper.h"


// flag to check if this plugin has initialized.
bool g_hasInitialized = false;


static bool isStartEvent = false;
static HANDLE g_EventThreadHandle = NULL;
static SESSION *g_Session = NULL;

EXPORT_API SESSION* CreateSession()
{
	SESSION* session = (SESSION*)calloc(sizeof(SESSION), 1);
	if (NULL == session)return NULL;
	session->player = new LeoPlayer::WinPlayer();
	session->player->Reset();
	session->sharedTextureMutex_ = new std::mutex();
	g_Session = session;
	return session;
}
EXPORT_API void DestroySession(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->ReleasePlayer();
	delete session->player;
}
EXPORT_API void SetWindowId(SESSION* session, void*  windowId)
{
	if (NULL == session || session->player == NULL) {
		return;
	}

	session->player->SetWindowId((int64_t)windowId);
	

}
EXPORT_API int OpenMovie(SESSION* session, const char* path) {
	if (NULL == session || session->player == NULL) {
		return -1;
	}
	session->player->SetDataSource(path);
	session->player->Start();
	return 0;
}
EXPORT_API void UpdatePlaybackInfo(SESSION*session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->UpdatePlaybackInfo();

}

EXPORT_API void TogglePause(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->Pause();
}

EXPORT_API void ToggleMute(SESSION* session,bool mute)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	session->player->SetMute(mute);
}

EXPORT_API bool IsPlaying(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return false;
	}
	return session->player->IsPlaying();
}

EXPORT_API double GetCurrentPosition(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return 0;
	}
	return session->player->GetCurrentPosition();
}

EXPORT_API double GetDuration(SESSION* session)
{
	if (NULL == session || session->player == NULL) {
		return 0;
	}
	return session->player->GetDuration();
}

EXPORT_API void SeekTo(SESSION* session, double position)
{
	if (NULL == session || session->player==NULL) {
		return;
	}
	session->player->SeekTo(position);
}

EXPORT_API void SetVolume(SESSION* session, double volume)
{
	if (NULL == session || session->player == NULL) {
		return;
	}
	return session->player->SetVolume(volume);
}

EXPORT_API double GetVolume(SESSION* session)
{
	return session->player->GetVolume();
}

EXPORT_API  int __stdcall GetPlaybackInfo(SESSION* session, char* s)
{
	if (NULL == session || session->player == NULL) {
		return NULL;
	}
	LeoPlayer::PlaybackInfo info = session->player->GetPlaybackInfo();
	neb::CJsonObject oJson = CJsonHelper::GetJsonFromPlaybackInfo(info);
	std::string str = oJson.ToString();
	const char* c = str.c_str();
	strcpy(s,c);
	return str.size();
	//const int len = str.length()+1;
	
	//char* c;
	//c = new char[len];
	//strcpy(c, str.c_str());
	//return str.c_str();
}

EXPORT_API void SetTrack(SESSION* session, int type, int index)
{
	if (NULL == session || session->player == NULL) {
		return;
	}

	return session->player->SetTrack(LeoPlayer::MPVTrack::TrackType (type), index);
}
