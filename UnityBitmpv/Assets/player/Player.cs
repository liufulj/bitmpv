using LitJson;
using System;
using System.Runtime.InteropServices;

namespace bitplayer
{
    public class Player
    {

      

        public const string dllname = "bitmpv";
        /// <summary>
        /// 解决不能播放中文文件的问题
        /// </summary>
        /// <param name="session"></param>
        /// <param name="path"></param>
        /// <returns></returns>
        public static int OpenMovieDefault(IntPtr session, string path)
        {

            byte[] fileBytes = System.Text.Encoding.UTF8.GetBytes(path + "\0");
            string data = System.Text.Encoding.Default.GetString(fileBytes);
            return OpenMovie(session, data);
        }

        public static PlaybackInfo GetPlaybackInfo(IntPtr session)
        {
            bitplayer.Player.UpdatePlaybackInfo(session);
            byte[] s = new byte[4 * 1024];
            int t = bitplayer.Player.GetPlaybackInfo(session, ref s[0]);//用字节数组接收动态库传过来的字符串
            string strGet = System.Text.Encoding.Default.GetString(s, 0, t); //将字节数组转换为字符串
            try
            {
                PlaybackInfo config = JsonMapper.ToObject<PlaybackInfo>(strGet);

                return config;
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            return new PlaybackInfo();
        }

    

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateSession();
        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroySession(IntPtr session);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        private static extern int OpenMovie(IntPtr session, string path);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Start(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Stop(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void InitExtendDevice(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetWindowId(IntPtr session, IntPtr winId, bool isTexture);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void TogglePause(IntPtr session);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void ToggleMute(IntPtr session,bool mute);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool IsPlaying(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern double GetCurrentPosition(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern double GetDuration(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SeekTo(IntPtr session,double postion);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern double GetVolume(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetVolume(IntPtr session, double volume);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void UpdatePlaybackInfo(IntPtr session);

        [DllImport(dllname, CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        private static extern int GetPlaybackInfo(IntPtr session,ref byte str);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetTrack(IntPtr session,int type,int index);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern int WaitForEvent(IntPtr session);

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern int WaitMpvEvent(IntPtr session);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void UpdateRender(IntPtr session);



        // Native plugin rendering events are only called if a plugin is used
        // by some script. This means we have to DllImport at least
        // one function in some active script.
        // For this example, we'll call into plugin's SetTimeFromUnity
        // function and pass the current time so the plugin can animate.


        [DllImport("bitmpv")]
        public static extern void SetTimeFromUnity(float t);


        // We'll also pass native pointer to a texture in Unity.
        // The plugin will fill texture data from native code.
        [DllImport("bitmpv")]
        public static extern void SetTextureFromUnity(System.IntPtr texture, int w, int h);

        // We'll pass native pointer to the mesh vertex buffer.
        // Also passing source unmodified mesh data.
        // The plugin will fill vertex data from native code.

        [DllImport("bitmpv")]
        public static extern void SetMeshBuffersFromUnity(IntPtr vertexBuffer, int vertexCount, IntPtr sourceVertices, IntPtr sourceNormals, IntPtr sourceUVs);


        [DllImport("bitmpv")]
        public static extern IntPtr GetRenderEventFunc();


    }
}

