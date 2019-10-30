using UnityEngine;
using System;
using System.Collections;
using System.Runtime.InteropServices;
using System.Threading;
using UnityEngine.UI;
using bitplayer;

public class MediaPlayer : MonoBehaviour
{

    private static IntPtr _session;





    private bitplayer.PlaybackInfo info;

    private Thread threadEvent;

    public Material material;

    public GameObject panel;

    //private Sprite spriteA = Sprite.Create(;

    void Start()
    {
        _session = bitplayer.Player.CreateSession();
        bitplayer.Player.InitExtendDevice(_session);
        //CreateTextureAndPassToPlugin(3840,2160);
        CreateTextureAndPassToPlugin(800, 600);
        threadEvent = new Thread(new ThreadStart(WaitForPlayerEvent));

        StartCoroutine(CallPluginAtEndOfFrames());

        threadEvent.Start();
    }

    internal void Stop()
    {
        bitplayer.Player.Stop(_session);
    }

    internal bool IsPlaying()
    {
        return bitplayer.Player.IsPlaying(_session);
    }

    private void CreateTextureAndPassToPlugin(int width, int height)
    {
        // Create a texture
        Texture2D tex = new Texture2D(width, height, TextureFormat.ARGB32, false);
        // Set point filtering just so we can see the pixels clearly
        tex.filterMode = FilterMode.Point;
        // Call Apply() so it's actually uploaded to the GPU
        tex.Apply();

        if (material != null)
        {
            material.mainTexture = tex;
            //material.mainTextureScale = new Vector2(-1, 1);
        }
        //var video = new Material(material);
        if (panel != null)
        {

            panel.GetComponent<Renderer>().material.mainTexture = tex;
            panel.GetComponent<Renderer>().material.mainTextureScale = new Vector2(-1, 1);
        }
        //else
        bitplayer.Player.SetWindowId(_session, tex.GetNativeTexturePtr(), true);

    }

    internal void SeekTo(double v)
    {
        bitplayer.Player.SeekTo(_session, v);
    }

    internal void PlayOrPause()
    {
        bitplayer.Player.TogglePause(_session);
    }

    internal void Mute(bool v)
    {
        bitplayer.Player.ToggleMute(_session, v);
    }

    private void Update()
    {
        if (startFile)
        {
            startFile = false;
            UpdateVideoInfo();
            _audioIndex = 0;
            _subIndex = 0;
            Debug.LogWarning("info is:" + info.width + "," + info.height);
            CreateTextureAndPassToPlugin(info.width, info.height);
        }
        else
        {
            bitplayer.Player.UpdateRender(_session);


        }
    }

    private IEnumerator CallPluginAtEndOfFrames()
    {
        while (true)
        {
            // Wait until all frame rendering is done
            yield return new WaitForEndOfFrame();

            // Set time for the plugin
            bitplayer.Player.SetTimeFromUnity(Time.timeSinceLevelLoad);
            GL.IssuePluginEvent(bitplayer.Player.GetRenderEventFunc(), PLAYER_EVENT_DRAW);

        }
    }


    bool startFile = false;
    private const int MPV_EVENT_FILE_LOADED = 8;
    private const int PLAYER_EVENT_DRAW = 666;
    private const int PLAYER_EVENT_MPV = 333;

    public void WaitForPlayerEvent()
    {
        while (!isDestory)
        {

            try
            {
                int eventCode = bitplayer.Player.WaitForEvent(_session);
      
                if (eventCode == PLAYER_EVENT_DRAW)
                {

                    

                } else if (eventCode == PLAYER_EVENT_MPV)
                {
                    int eventMpv = 0;
                    while (true)
                    {
                        eventMpv = bitplayer.Player.WaitMpvEvent(_session);
                        if (eventMpv == 0)
                            break;
                        if (eventMpv == MPV_EVENT_FILE_LOADED)
                        {
                            startFile = true;
                        }
                        // Debug.LogError("eventcode is:" + eventMpv);
                    }


                }
                else if (eventCode == -1)
                {
                    Thread.Sleep(100);
                }
            }
            catch
            {
                Thread.Sleep(100);
            }
            Thread.Sleep(2);
        }
    }

    internal float GetVolume()
    {
        return (float)(bitplayer.Player.GetVolume(_session)/100.0);
    }

    internal void SetVolume(float value)
    {
        bitplayer.Player.SetVolume(_session, value * 100.0);
    }

    private bool isDestory = false;

    private void UpdateVideoInfo()
    {
        info = bitplayer.Player.GetPlaybackInfo(_session);
    }

    public void OpenFileVideo(string filename)
    {

        bitplayer.Player.OpenMovieDefault(_session, filename);
    }

    void OnDestroy()
    {
        bitplayer.Player.Stop(_session);
        isDestory = true;

    }

    private int _audioIndex = 0;
    private int _subIndex = 0;

    public void NextAudio()
    {
        if (info.audioTracks == null)
        {
            return;
        }
        int index = _audioIndex + 1;

        int count = info.audioTracks.Count;

        if (count < 1 || index > count - 1)
        {
            index = -1;
        }
        if (index >= 0)
        {
            bitplayer.Player.SetTrack(_session, (int)MPVTrack.TrackType.AUDIO, info.audioTracks[index].id);
        }
        else
        {
            bitplayer.Player.SetTrack(_session, (int)MPVTrack.TrackType.AUDIO, 0);
        }
        _audioIndex = index;

    }
    public void NextSub()
    {
        if (info.subTracks == null)
        {
            return;
        }
        int index = _subIndex + 1;

        int count = info.subTracks.Count;

        if (count < 1 || index > count - 1)
        {
            index = -1;
        }
        if (index >= 0)
        {
            bitplayer.Player.SetTrack(_session, (int)MPVTrack.TrackType.SUB, info.subTracks[index].id);
        }
        else
        {
            bitplayer.Player.SetTrack(_session, (int)MPVTrack.TrackType.SUB, 0);
        }
        _subIndex = index;

    }

    public double GetDurationSencond() //√Î
    {
        if (info == null)
        {
            return 0;
        }
        return info.duration;
    }
    public double GetPosition()
    {
        return bitplayer.Player.GetCurrentPosition(_session);
    }
}

