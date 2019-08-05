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

        private bitplayer.PlaybackInfo info;

        public Main()
        {
            InitializeComponent();
            this.Icon = Icon.FromHandle(Resources.bitmpv_logo.GetHicon());
            this.timerPlay.Interval = 1000;

            this.trackBarSound.Maximum = 100;
            this.trackBarSound.Minimum = 0;
            this.trackBarSound.Value = 0;
      
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

                    changePlayOrPause();
                    changeMute(isMute);


                }
            }

        }

        private void changeMute(bool muteFlag)
        {
            if (muteFlag)
            {
                soundVol.BackgroundImage = Resources.mute;
            }
            else
            {
                soundVol.BackgroundImage = Resources.sound;
            }
            bitplayer.Player.ToggleMute(session, muteFlag);
        }

        private void Main_Load(object sender, EventArgs e)
        {
            session = bitplayer.Player.CreateSession();
            if (session != null)
            {
                bitplayer.Player.SetWindowId(session, (System.IntPtr)this.video.Handle.ToInt64(), false);
                this.trackBarSound.Value = (int)bitplayer.Player.GetVolume(session);
                Console.WriteLine("" + bitplayer.Player.GetVolume(session));
                changePlayOrPause();
                changeMute(isMute);
            }
        }

        private void PlayOrPause_Click(object sender, EventArgs e)
        {
            if (session != null)
            {

                bitplayer.Player.TogglePause(session);
                changePlayOrPause();
            }
        }

        private void changePlayOrPause()
        {
            if (session != null)
            {
                if (bitplayer.Player.IsPlaying(session))
                {
                    playOrPause.BackgroundImage = Resources.pause;
                }
                else
                {
                    playOrPause.BackgroundImage = Resources.play;
                }
            }
        }

        private void SoundVol_Click(object sender, EventArgs e)
        {
            if (session != null)
            {
                isMute = !isMute;
                changeMute(isMute);

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
                        UpdateVideoInfo();

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

        private void UpdateVideoInfo()
        {
            info = bitplayer.Player.GetPlaybackInfo(session);
            UpdateContextMenu();
        }

        private void UpdateContextMenu()
        {
            videoContextMenuStrip.Items.Clear();

            if (info.audioTracks != null && info.audioTracks.Count > 0)
            {
                ToolStripMenuItem subItem;
                subItem = AddContextMenu("音频", videoContextMenuStrip.Items, null);
                subItem.Name = "audio";
                ToolStripMenuItem nilItem = AddContextMenu("无", subItem.DropDownItems, new EventHandler(OnMenuClick),"audio0");
                bool isNull = true;
                foreach (MPVTrack track in info.audioTracks)
                {

                    ToolStripMenuItem item =AddContextMenu("轨道" + track.id, subItem.DropDownItems, new EventHandler(OnMenuClick),"audio"+track.id);
                    if (info.aid == track.id)
                    {
                        item.Checked = true;
                        isNull = false;
                    }
                    else
                    {
                        item.Checked = false;
                    }
                    
                }
                if (isNull)
                {
                    nilItem.Checked = true;
                }
            }

            if (info.subTracks != null && info.subTracks.Count > 0)
            {
                ToolStripMenuItem subItem;
                subItem = AddContextMenu("字幕", videoContextMenuStrip.Items, null);
                subItem.Name = "sub";
                ToolStripMenuItem nilItem = AddContextMenu("无", subItem.DropDownItems, new EventHandler(OnMenuClick),"sub0");
                bool isNull = true;
                foreach (MPVTrack track in info.subTracks)
                {
                    ToolStripMenuItem item = AddContextMenu("字幕" + track.id, subItem.DropDownItems, new EventHandler(OnMenuClick),"sub"+track.id);
                    if (info.sid == track.id)
                    {
                        item.Checked = true;
                        isNull = false;
                    }
                    else
                    {
                        item.Checked = false;
                    }

                }
                if (isNull)
                {
                    nilItem.Checked = true;
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

        private void OnMenuClick(object sender, EventArgs e)
        {
            ToolStripMenuItem item = sender as ToolStripMenuItem;
            try
            {
                string tag = item.Tag.ToString();
                if (tag.StartsWith("audio"))
                {
                    int id = Int32.Parse(tag.Replace("audio", ""));
                    bitplayer.Player.SetTrack(session,(int) MPVTrack.TrackType.AUDIO, id);
                }
                else if (tag.StartsWith("sub"))
                {
                    int id = Int32.Parse(tag.Replace("sub", ""));
                    bitplayer.Player.SetTrack(session, (int)MPVTrack.TrackType.SUB, id);
                }
            }
            catch
            {

            }

            UpdateVideoInfo();
        
            Console.WriteLine(item.Tag);
        }

        private ToolStripMenuItem AddContextMenu(string text, ToolStripItemCollection cms, EventHandler callback, string tag = "")
        {
            if (text == "-")
            {
                ToolStripSeparator tsp = new ToolStripSeparator();
                cms.Add(tsp);
                return null;
            }
            else if (!string.IsNullOrEmpty(text))
            {
                ToolStripMenuItem tsmi = new ToolStripMenuItem(text);
                if (tag == "")
                {
                    tsmi.Tag = text + "TAG";
                }
                else
                {
                    tsmi.Tag = tag;
                }
                
                if (callback != null) tsmi.Click += callback;
                cms.Add(tsmi);

                return tsmi;
            }

            return null;
        }

    }
}
