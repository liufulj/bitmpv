#include"stdafx.h"
#include "MPVTrack.h"

namespace LeoPlayer {
	MPVTrack::MPVTrack()
	{
	}


	MPVTrack::~MPVTrack()
	{
	}
	MPVTrack::TrackType MPVTrack::GetTrackType(std::string trackType)
	{
		if (trackType == "video") 
		{
			return TrackType::VIDEO;
		}
		else if (trackType == "audio")
		{
			return TrackType::AUDIO;
		}
		else if (trackType == "sub")
		{
			return TrackType::SUB;
		}
		else
		{
			return TrackType::SECOND_SUB;
		}
	}
}