using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bitplayer
{
    [Serializable]
    public class PlaybackInfo
    {
        public int volume;
        public int aid;
        public int vid;
        public int sid;
        public int secondSid;
        public int rotation;
        public int width;
        public int height;
        public double duration;
        public List<MPVTrack> audioTracks;
        public List<MPVTrack> videoTracks;
        public List<MPVTrack> subTracks;
    }
    [Serializable]
    public class MPVTrack
    {
        public enum TrackType
        {
            AUDIO, VIDEO, SUB, SECOND_SUB
        };

        public int id;
        public TrackType type;
        public int isDefault;
        public int isForced;
        public int isSelected;
        public int isExternal;
        public int srcId;
        public string title;
        public string lang;
        public string codec;
        public string externalFilename;
        public int isAlbumart;
        public string decoderDesc;
        public int demuxW;
        public int demuxH;
        public double demuxFps;
        public int demuxChannelCount;
        public int demuxSamplerate;
        public string demuxChannels;
    }
}
