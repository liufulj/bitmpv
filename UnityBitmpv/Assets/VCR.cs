#if UNITY_4_6 || UNITY_4_7 || UNITY_4_8 || UNITY_5 || UNITY_5_4_OR_NEWER
	#define UNITY_FEATURE_UGUI
#endif

using UnityEngine;
#if UNITY_FEATURE_UGUI


namespace RenderHeads.Media.AVProVideo.Demos
{
	/// <summary>
	public class VCR : MonoBehaviour 
	{
        public string[] _videoFiles = { "E:\\tmp\\test.mp4", "E:\\tmp\\test1.mp4", "E:\\tmp\\test2.mp4" };

        private int index = 0;

        public MediaPlayer mediaPlayer;

    

        public void NetVideo()
        {
            index++;
            index = index % 3;
            if (mediaPlayer.IsPlaying())
            {
                mediaPlayer.Stop();
            }
            if (mediaPlayer != null)
            {
                mediaPlayer.OpenFileVideo(_videoFiles[index]);
            }
        }

    }
}
#endif