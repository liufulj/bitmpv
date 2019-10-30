#if UNITY_4_6 || UNITY_4_7 || UNITY_4_8 || UNITY_5 || UNITY_5_4_OR_NEWER
#define UNITY_FEATURE_UGUI
#endif

using System.Collections;
using UnityEngine;
using UnityEngine.UI;
#if UNITY_FEATURE_UGUI


namespace RenderHeads.Media.AVProVideo.Demos
{
	/// <summary>
	public class VCR : MonoBehaviour 
	{
        public string[] _videoFiles = { "The.mkv", "E:\\tmp\\test.mp4", "E:\\tmp\\test1.mp4", "E:\\tmp\\test2.mp4" };

        private int index = 0;

        public MediaPlayer mediaPlayer;

        public Slider _videoSeekSlider;
        private float _setVideoSeekSliderValue;
        private float position = 0;
        private float volumeValue = 0;
        public Slider _audioVolumeSlider;
        private float _setAudioVolumeSliderValue=0;

        public GameObject _checkMark;


        private void Start()
        {
            StartCoroutine(Timer());
        }

        public void NetVideo()
        {
            index = index % _videoFiles.Length;
            if (mediaPlayer.IsPlaying())
            {
                mediaPlayer.Stop();
            }
            if (mediaPlayer != null)
            {
                mediaPlayer.OpenFileVideo(_videoFiles[index]);
            }
            index++;
        }

        private void Update()
        {
            if (mediaPlayer && _videoSeekSlider && mediaPlayer.IsPlaying())
            {

              _setVideoSeekSliderValue = position;
              _videoSeekSlider.value = position;
            }
            if (mediaPlayer && _audioVolumeSlider && mediaPlayer.IsPlaying())
            {

              

                _setAudioVolumeSliderValue = volumeValue;
                _audioVolumeSlider.value = volumeValue;
            }

        }


        public void PlayOrPause()
        {
            mediaPlayer.PlayOrPause();
        }

        public void NextAudio()
        {
            mediaPlayer.NextAudio();
        }

        public void NextSub()
        {
            mediaPlayer.NextSub();
        }

        private bool isMute = false;

        public void Mute()
        {
            isMute = !isMute;
            mediaPlayer.Mute(isMute);
        }

        public void OnVideoSeekSlider()
        {
            if (mediaPlayer && _videoSeekSlider &&( _videoSeekSlider.value != _setVideoSeekSliderValue&& Mathf.Abs( _videoSeekSlider.value-_setVideoSeekSliderValue)>0.01))
            {
                mediaPlayer.SeekTo(_videoSeekSlider.value * mediaPlayer.GetDurationSencond());
            }
        }


       

        public void OnAudioVolumeSlider()
        {
            if (mediaPlayer && _audioVolumeSlider && (_audioVolumeSlider.value != _setAudioVolumeSliderValue && Mathf.Abs(_audioVolumeSlider.value- _setAudioVolumeSliderValue) > 0.01))
            {
                mediaPlayer.SetVolume(_audioVolumeSlider.value);
            }
        }


        private IEnumerator Timer()
        {
            while (true)
            {
                yield return new WaitForSeconds(1.0f);
                double time = mediaPlayer.GetPosition();
                double duration = mediaPlayer.GetDurationSencond();
                position= Mathf.Clamp((float)(time / duration), 0.0f, 1.0f);
                volumeValue = mediaPlayer.GetVolume();
                
            }
        }




    }
}
#endif