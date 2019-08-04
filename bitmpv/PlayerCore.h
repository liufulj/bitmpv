#ifndef PLAYER_CORE_H_
#define PLAYER_CORE_H_
#include "MPVController.h"
#include "MPVTrack.h"
#include "PlaybackInfo.h"
namespace LeoPlayer {
	class PlayerCore
	{
	public:
		PlayerCore();
		~PlayerCore();


		//MARK control
		void StartMPV();
		void Open(std::string path);
		void GetSelectedTracks();
		void GetTrackInfo();
		void ChangeNextAudio();
		void ChangeNextSub();
		PlaybackInfo GetPlaybackInfo();
		double GetCurrentPosition();
		double GetDuration();
		void SetLoop(bool loop);
		bool GetLoop();


		//MARK -MPV commands
		void TogglePause(bool pause);
		void ToggleMute(bool mute);
		void Stop();
		void Seek(double time);
		void FrameStep(bool backwards = false);
		void SetVolume(double volume);
		double GetVolume();
		void SetTrack(MPVTrack::TrackType type, int index);
		void SetSpeed(double speed);
		//void SetVideoAspect(std::string aspect);
		void SetVideoRotate(int degree);
		void SetAudioDelay(double delay);
		void SetSubDelay(double delay);
		void SetWindowId(int64_t id);
		mpv_handle * GetMPVHandle();


	private:
		MPVController mpv;
		PlaybackInfo info;
	};
}



#endif // !PLAYER_CORE_H_


