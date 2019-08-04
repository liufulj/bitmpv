#include "stdafx.h"
#include "CJsonHelper.h"

neb::CJsonObject CJsonHelper::GetJsonFromPlaybackInfo(LeoPlayer::PlaybackInfo info)
{
	neb::CJsonObject oJson;
	oJson.Add("volume", info.volume);
	oJson.Add("aid", info.aid);
	oJson.Add("vid", info.vid);
	oJson.Add("sid", info.sid);
	oJson.Add("secondSid", info.secondSid);
	oJson.Add("rotation", info.secondSid);
	std::list<LeoPlayer::MPVTrack>::iterator it;
	for (it = info.audioTracks.begin(); it != info.audioTracks.end(); it++) {
		neb::CJsonObject item = GetJsonFromMPVTrack(*it);
		oJson.Add("audioTracks", item);
	}
	for (it = info.videoTracks.begin(); it != info.videoTracks.end(); it++) {
		neb::CJsonObject item = GetJsonFromMPVTrack(*it);
		oJson.Add("audioTracks", item);
	}
	for (it = info.subTracks.begin(); it != info.subTracks.end(); it++) {
		neb::CJsonObject item = GetJsonFromMPVTrack(*it);
		oJson.Add("subTracks", item);
	}
	return oJson;
}

neb::CJsonObject CJsonHelper::GetJsonFromMPVTrack(LeoPlayer::MPVTrack track)
{
	LeoPlayer::MPVTrack* it = &track;
	neb::CJsonObject item;
	item.Add("id", it->id);
	item.Add("type", it->type);
	item.Add("isDefault", it->isDefault);
	item.Add("isForced", it->isForced);
	item.Add("isSelected", it->isSelected);
	item.Add("isExternal", it->isExternal);
	item.Add("srcId", it->srcId);
	item.Add("title", it->title);
	item.Add("lang", it->lang);
	item.Add("codec", it->codec);
	item.Add("externalFilename", it->externalFilename);
	item.Add("isAlbumart", it->isAlbumart);
	item.Add("decoderDesc", it->decoderDesc);
	item.Add("demuxW", it->demuxW);
	item.Add("demuxH", it->demuxH);
	item.Add("demuxFps", it->demuxFps);
	item.Add("demuxChannelCount", it->demuxChannelCount);
	item.Add("demuxSamplerate", it->demuxSamplerate);
	item.Add("demuxChannels", it->demuxChannels);
	return item;
}
