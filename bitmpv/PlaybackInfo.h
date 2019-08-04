#ifndef PLAYBACK_INFO_H_
#define PLAYBACK_INFO_H_
#include<list>
#include"MPVTrack.h"
namespace LeoPlayer {
	struct PlaybackInfo
	{
		int volume = 0;
		int aid = 0;
		int vid = 0;
		int sid = 0;
		int secondSid = 0;
		int rotation = 0;
		double timePos = 0;
		double duration = 0;
		std::list<MPVTrack> audioTracks;
		std::list<MPVTrack> videoTracks;
		std::list<MPVTrack> subTracks;
	};
}

#endif // !PLAYBACK_INFO_H_


