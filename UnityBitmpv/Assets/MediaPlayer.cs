using UnityEngine;
using System;
using System.Collections;
using System.Runtime.InteropServices;
using System.Threading;

public class MediaPlayer : MonoBehaviour
{

    private static IntPtr _session;

    private bool isMute = false;

    private double duration = 0;

    private double postion = 0;

 

    private bitplayer.PlaybackInfo info;

    private Thread threadEvent;

    public Material material;

    void Start()
	{
        _session = bitplayer.Player.CreateSession();
        bitplayer.Player.InitExtendDevice(_session);
        threadEvent = new Thread(new ThreadStart(WaitForPlayerEvent));
        StartCoroutine(Timer());
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

    private void CreateTextureAndPassToPlugin(int width,int height)
	{
		// Create a texture
		Texture2D tex = new Texture2D(width, height, TextureFormat.ARGB32,false);
		// Set point filtering just so we can see the pixels clearly
		tex.filterMode = FilterMode.Point;
		// Call Apply() so it's actually uploaded to the GPU
		tex.Apply();

        // Set texture onto our material
        //GetComponent<Renderer>().material.mainTexture = tex;
        //      GetComponent<Renderer>().material.mainTextureScale = new Vector2(-1, 1);
        if (material != null)
        {
            material.mainTexture = tex;
            //material.mainTextureScale = new Vector2(-1, 1);

        }

        bitplayer.Player.SetWindowId(_session, tex.GetNativeTexturePtr(), true);
    }


    private void Update()
    {
        if (startFile)
        {
            startFile = false;
            UpdateVideoInfo();
          
        }
        bitplayer.Player.UpdateRender(_session);
    }

    private IEnumerator CallPluginAtEndOfFrames()
    {
        while (true)
        {
            // Wait until all frame rendering is done
            yield return new WaitForEndOfFrame();

            // Set time for the plugin
            bitplayer.Player.SetTimeFromUnity(Time.timeSinceLevelLoad);

            GL.IssuePluginEvent(bitplayer.Player.GetRenderEventFunc(), 666);

        }
    }

    bool hasFrame = false;
    bool startFile = false;


    public void WaitForPlayerEvent()
    {
        while (!isDestory)
        {
            
            try
            {
                int eventCode = bitplayer.Player.WaitForEvent(_session);
                //Debug.LogError("eventcode is:" + eventCode);
                if(eventCode == 666)
                {

                    hasFrame = true;
                  
                }else if (eventCode == 333)
                {
                    startFile = true;
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
            Thread.Sleep(5);

        }
    }

    private IEnumerator Timer()
    {
        while (true)
        {
            yield return new WaitForSeconds(1.0f);
            if (bitplayer.Player.IsPlaying(_session))
            {
             


                if (duration == 0)
                {
                    duration = bitplayer.Player.GetDuration(_session);

                }
                postion = bitplayer.Player.GetCurrentPosition(_session);
                
            }
        }
    }

    private bool isDestory = false;

    private void UpdateVideoInfo()
    {
        info = bitplayer.Player.GetPlaybackInfo(_session);
    }

    public void OpenFileVideo(string filename)
    {
        duration = 0;
        postion = 0;
        bitplayer.Player.OpenMovieDefault(_session, filename);
    }

    void OnDestroy()
    {
        bitplayer.Player.Stop(_session);
        isDestory = true;

    }
}

