using System;
using System.Runtime.InteropServices;

namespace bitplayer
{
    public class Player
    {

        public const int EVENT_REDRAW = 1;

        public const int EVENT_MPV = 2;

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

        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateSession();
        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroySession(IntPtr session);


        [DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        private static extern int OpenMovie(IntPtr session, string path);

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
        public static extern int GetPlaybackInfo(IntPtr session,ref byte str);

        //[DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        //public static extern void StartEvent(IntPtr session);

        //[DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        //public static extern void StopEvent(IntPtr session);

        //[DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        //public static extern void UpdateRender(IntPtr session);
        //[DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        //public static extern void DoProcess(IntPtr session);




        ////unity render plugin
        //[DllImport(dllname, CallingConvention = CallingConvention.Cdecl)]
        //public static extern IntPtr GetRenderEventFunc();



    }
}

