#ifndef MPV_TRACK_H_
#define MPV_TRACK_H_
namespace LeoPlayer {
	class MPVTrack
	{
	public:
		MPVTrack();
		~MPVTrack();


		enum TrackType
		{
			AUDIO,VIDEO,SUB,SECOND_SUB
		};
		static TrackType GetTrackType(std::string trackType);
		int id;
		TrackType type;
		bool isDefault;
		bool isForced;
		bool isSelected;
		bool isExternal;
		int srcId;
		std::string title;
		std::string lang;
		std::string codec;
		std::string externalFilename;
		bool isAlbumart;
		std::string decoderDesc;
		int demuxW;
		int demuxH;
		double demuxFps;
		int demuxChannelCount;
		int demuxSamplerate;
		std::string demuxChannels;
		
	};
}




#endif // !MPV_TRACK_H_


