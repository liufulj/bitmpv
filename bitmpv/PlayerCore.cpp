#include"stdafx.h"
#include "PlayerCore.h"
#include "MPVController.h"

namespace LeoPlayer {
	PlayerCore::PlayerCore()
	{
		this->mpv = MPVController(this);
	}


	PlayerCore::~PlayerCore()
	{
	}
	void PlayerCore::StartMPV()
	{
		this->mpv.MPVInit();
		this->mpv.SetString(MPVProperty::audioDevice, "auto");

		
	}
	void PlayerCore::Open(std::string path)
	{
		std::string pathes[1];
		pathes[0] = path;
		this->mpv.Command(MPVCommand::loadfile, pathes,1,true);
	}
	void PlayerCore::GetSelectedTracks()
	{
		this->info.volume = this->mpv.GetDouble(MPVOption::Audio::volume);
		this->info.aid = this->mpv.GetInt(MPVOption::TrackSelection::aid);
		this->info.vid = this->mpv.GetInt(MPVOption::TrackSelection::vid);
		this->info.sid = this->mpv.GetInt(MPVOption::TrackSelection::sid);
		this->info.secondSid = this->mpv.GetInt(MPVOption::Subtitles::secondarySid);
		info.width = mpv.GetInt(MPVProperty::width);
		info.height = mpv.GetInt(MPVProperty::height);
	}
	void PlayerCore::GetTrackInfo()
	{
		info.audioTracks.clear();
		info.videoTracks.clear();
		info.subTracks.clear();
		int trackCount = mpv.GetInt(MPVProperty::trackListCount);
		info.duration = mpv.GetDouble(MPVProperty::duration);
		for(int index =0;  index < trackCount;index++)
		{
			// Get info for each track
			std::string trackType = mpv.GetString(MPVProperty::trackListNType(index));
			if (trackType=="") {
				continue;
			}
			MPVTrack track = MPVTrack();
			track.id= mpv.GetInt(MPVProperty::trackListNId(index));
			track.type = MPVTrack::GetTrackType(trackType);
			track.isDefault = mpv.GetFlag(MPVProperty::trackListNDefault(index));
			track.isForced = mpv.GetFlag(MPVProperty::trackListNForced(index));
			track.isSelected = mpv.GetFlag(MPVProperty::trackListNSelected(index));
			track.isExternal = mpv.GetFlag(MPVProperty::trackListNExternal(index));
			track.srcId = mpv.GetInt(MPVProperty::trackListNSrcId(index));
			track.title = mpv.GetString(MPVProperty::trackListNTitle(index));
			track.lang = mpv.GetString(MPVProperty::trackListNLang(index));
			track.codec = mpv.GetString(MPVProperty::trackListNCodec(index));
			track.externalFilename = mpv.GetString(MPVProperty::trackListNExternalFilename(index));
			track.isAlbumart = mpv.GetString(MPVProperty::trackListNAlbumart(index)) == "yes";
			track.decoderDesc = mpv.GetString(MPVProperty::trackListNDecoderDesc(index));
			track.demuxW = mpv.GetInt(MPVProperty::trackListNDemuxW(index));
			track.demuxH = mpv.GetInt(MPVProperty::trackListNDemuxH(index));
			track.demuxFps = mpv.GetDouble(MPVProperty::trackListNDemuxFps(index));
			track.demuxChannelCount = mpv.GetInt(MPVProperty::trackListNDemuxChannelCount(index));
			track.demuxChannels = mpv.GetString(MPVProperty::trackListNDemuxChannels(index));
			track.demuxSamplerate = mpv.GetInt(MPVProperty::trackListNDemuxSamplerate(index));

			// add to lists
			switch (track.type) {
			case MPVTrack::TrackType::AUDIO:
				info.audioTracks.push_back(track);
				break;
			case MPVTrack::TrackType::VIDEO:
				info.videoTracks.push_back(track);
				break;
			case MPVTrack::TrackType::SUB:
				info.subTracks.push_back(track);
			default:
				break;
			}
		}

	
	}

	void PlayerCore::ChangeNextAudio()
	{
		GetTrackInfo();
		GetSelectedTracks();
		int size = info.audioTracks.size();
		if (info.aid < size) {
			int id = info.aid + 1;
			SetTrack(LeoPlayer::MPVTrack::AUDIO, id);
		}
		else {
			SetTrack(LeoPlayer::MPVTrack::AUDIO, 1);
		}

	}

	void PlayerCore::ChangeNextSub()
	{
		GetTrackInfo();
		GetSelectedTracks();
		int size = info.subTracks.size();
		if (info.sid < size) {
			int id = info.sid + 1;
			SetTrack(LeoPlayer::MPVTrack::SUB, id);
		}
		else {
			SetTrack(LeoPlayer::MPVTrack::SUB, 0);
		}
	}

	PlaybackInfo PlayerCore::GetPlaybackInfo()
	{
		return info;
	}

	double PlayerCore::GetCurrentPosition()
	{

		return  mpv.GetDouble(MPVProperty::timePos);
	}

	double PlayerCore::GetDuration()
	{
		
		return mpv.GetDouble(MPVProperty::duration);;
	}

	void PlayerCore::SetLoop(bool loop)
	{
	}

	bool PlayerCore::GetLoop()
	{
		return false;
	}
	
	void PlayerCore::TogglePause(bool pause) {
		if (this->mpv.GetFlag(MPVProperty::eofReached)) {
			Seek(0);
		}
		this->mpv.SetFlag(MPVOption::PlaybackControl::pause, pause);
	}
	void PlayerCore::ToggleMute(bool mute)
	{
		this->mpv.SetFlag(MPVOption::Audio::mute, mute);
	}
	void PlayerCore::Stop()
	{
		this->mpv.Command(MPVCommand::stop);
	}
	void PlayerCore::Seek(double time)
	{
		std::string pathes[2];
		pathes[0] = std::to_string(time);
		pathes[1] = "absolute+exact";
		this->mpv.Command(MPVCommand::seek, pathes,2, true);
	}
	void PlayerCore::FrameStep(bool backwards)
	{
		if (backwards) {
			this->mpv.Command(MPVCommand::frameBackStep);
		}
		else {
			this->mpv.Command(MPVCommand::frameStep);
		}
	}
	void PlayerCore::SetVolume(double volume)
	{
		this->info.volume = volume;
		this->mpv.SetDouble(MPVOption::Audio::volume, volume);
	}
	double PlayerCore::GetVolume()
	{
		return this->mpv.GetDouble(MPVOption::Audio::volume);
	}
	void PlayerCore::SetTrack(MPVTrack::TrackType type, int index)
	{
		std::string name = "";
		switch (type)
		{
		case LeoPlayer::MPVTrack::AUDIO:
			name = MPVOption::TrackSelection::aid;
			break;
		case LeoPlayer::MPVTrack::VIDEO:
			name = MPVOption::TrackSelection::vid;
			break;
		case LeoPlayer::MPVTrack::SUB:
			name = MPVOption::TrackSelection::sid;
			break;
		case LeoPlayer::MPVTrack::SECOND_SUB:
			name = MPVOption::Subtitles::secondarySid;
			break;
		default:
			break;
		}
		this->mpv.SetInt(name, index);

	}
	void PlayerCore::SetSpeed(double speed)
	{
		this->mpv.SetDouble(MPVOption::PlaybackControl::speed, speed);
	}
	void PlayerCore::SetVideoRotate(int degree)
	{
		this->mpv.SetInt(MPVOption::Video::videoRotate, degree);
		info.rotation = degree;
	}
	void PlayerCore::SetAudioDelay(double delay)
	{
		mpv.SetDouble(MPVOption::Audio::audioDelay, delay);
	}
	void PlayerCore::SetSubDelay(double delay)
	{
		mpv.SetDouble(MPVOption::Subtitles::subDelay, delay);
	}
	void PlayerCore::SetWindowId(int64_t data)
	{
		mpv.SetInt(MPVOption::Window::wid, data);
	}
	mpv_handle * PlayerCore::GetMPVHandle()
	{
		return mpv.GetMPVHandle();
	}
}
