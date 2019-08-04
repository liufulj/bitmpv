#pragma once
#include"CJsonObject.hpp"
#include<list>
class CJsonHelper
{
public:
	static neb::CJsonObject GetJsonFromPlaybackInfo(LeoPlayer::PlaybackInfo info);
	static neb::CJsonObject GetJsonFromMPVTrack(LeoPlayer::MPVTrack track);
};

