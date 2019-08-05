#pragma once
#include"Player.h"

#include <mutex>



#if _MSC_VER
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

struct SESSION
{
	LeoPlayer::Player * player;
	bool isAvailable;
	bool shouldRender;
	int width;
	int height;
	bool gl;
	std::mutex *sharedTextureMutex_;
};


extern "C"
{
	EXPORT_API SESSION* CreateSession();
	EXPORT_API void DestroySession(SESSION* session);
	EXPORT_API void SetWindowId(SESSION* session, void*  windowId);
	EXPORT_API int OpenMovie(SESSION* session, const char* path);
	EXPORT_API void UpdatePlaybackInfo(SESSION*session);
	EXPORT_API void TogglePause(SESSION* session);
	EXPORT_API void ToggleMute(SESSION* session, bool mute);
	EXPORT_API bool IsPlaying(SESSION* session);
	EXPORT_API double GetCurrentPosition(SESSION* session);
	EXPORT_API double GetDuration(SESSION* session);
	EXPORT_API void SeekTo(SESSION* session,double position);
	EXPORT_API void SetVolume(SESSION* session, double volume);
	EXPORT_API double GetVolume(SESSION* session);
	EXPORT_API int __stdcall GetPlaybackInfo(SESSION* session,char* str);
	EXPORT_API  void SetTrack(SESSION* session,int type, int index);

}