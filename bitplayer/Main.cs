using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using bitplayer.Properties;
namespace bitplayer
{
    public partial class Main : Form
    {

        private IntPtr session;

        private bool isMute = false;

        private double duration = 0;

        private double postion = 0;

        private bool isOpenedFirst = false;

        public Main()
        {
            InitializeComponent();
            this.Icon = Icon.FromHandle(Resources.bitmpv_logo.GetHicon());
            this.timerPlay.Interval = 1000;

            this.trackBarSound.Maximum = 100;
            this.trackBarSound.Minimum = 0;
            this.trackBarSound.Value = 0;
            //this.Location = new Point(960, 480);
            //this.Show();
        }

        private void open_ToolStripMenuItem_Click(object sender, EventArgs e)
        {

            openFileDlg.FileName = String.Empty;
            if (openFileDlg.ShowDialog(this) == DialogResult.OK)
            {
                
                if (session != null)
                {
                    if (bitplayer.Player.IsPlaying(session))
                    {
                        this.timerPlay.Stop();
                    }
                    duration = 0;
                    postion = 0;
                    this.timerPlay.Start();
                    isOpenedFirst = true;
                    bitplayer.Player.OpenMovieDefault(session, openFileDlg.FileName);
                    isMute = true;
                    bitplayer.Player.ToggleMute(session, isMute);

                }
            }

        }

        private void Main_Load(object sender, EventArgs e)
        {
            session = bitplayer.Player.CreateSession();
            if (session != null)
            {
                bitplayer.Player.SetWindowId(session, (System.IntPtr)this.video.Handle.ToInt64(), false);
                this.trackBarSound.Value = (int)bitplayer.Player.GetVolume(session);
                Console.WriteLine("" + bitplayer.Player.GetVolume(session));

            }
        }

        private void PlayOrPause_Click(object sender, EventArgs e)
        {
            if (session != null)
            {

                bitplayer.Player.TogglePause(session);

            }
        }

        private void SoundVol_Click(object sender, EventArgs e)
        {
            if (session != null)
            {
                isMute = !isMute;
                bitplayer.Player.ToggleMute(session,isMute);

            }
        }

        private void TimerPlay_Tick(object sender, EventArgs e)
        {
            if (session != null)
            {
                if (bitplayer.Player.IsPlaying(session))
                {
                    if (isOpenedFirst)
                    {
                        isOpenedFirst = false;
                        bitplayer.Player.UpdatePlaybackInfo(session);
                        byte[] s = new byte[1024];
                        int t = bitplayer.Player.GetPlaybackInfo(session ,ref s[0]);//用字节数组接收动态库传过来的字符串
                        string strGet = System.Text.Encoding.Default.GetString(s, 0, s.Length); //将字节数组转换为字符串
                        Console.WriteLine(strGet);
                      
                        //string info = Marshal.PtrToStringAnsi(bitplayer.Player.GetPlaybackInfo(session));
                        //Console.WriteLine(info);
                    }


                    if (duration == 0)
                    {
                        duration = bitplayer.Player.GetDuration(session);
                        this.Invoke((EventHandler)delegate
                        {
                            this.progressBar.Value = 0;
                            this.progressBar.Minimum = 0;
                            this.progressBar.Maximum  = (int) duration;
                        });

                    }
                    postion = bitplayer.Player.GetCurrentPosition(session);

                    this.Invoke((EventHandler)delegate {
                        this.progressBar.Value = (int)postion;
                        this.timeLabel.Text = string.Format("{0} / {1}", bitplayer.StringUtils.SecondToHour(postion), bitplayer.StringUtils.SecondToHour(duration));
                    });

                    //Console.WriteLine(string.Format("{0},{1}", bitplayer.StringUtils.SecondToHour(postion), bitplayer.StringUtils.SecondToHour(duration)));
                }
            }
        }


        private void ProgressBar_MouseClick(object sender, MouseEventArgs e)
        {
         //   Console.WriteLine(""+e.X+","+ this.progressBar.Location.X+","+ this.progressBar.Size.Width);

            double choosePosion =duration * (e.X- this.progressBar.Location.X)/ this.progressBar.Size.Width;
            if (session != null)
            {
                bitplayer.Player.SeekTo(session, choosePosion);
            }
            this.progressBar.Value = (int)choosePosion;
        }

        private void TrackBarSound_Scroll(object sender, EventArgs e)
        {
            int postion = trackBarSound.Value;
            if (session != null)
            {
                bitplayer.Player.SetVolume(session, postion);
            }
        }
    }
}
