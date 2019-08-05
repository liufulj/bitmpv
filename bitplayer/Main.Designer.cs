namespace bitplayer
{
    partial class Main
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.video = new System.Windows.Forms.PictureBox();
            this.openFileDlg = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timeLabel = new System.Windows.Forms.Label();
            this.playOrPause = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.progressBar = new CCWin.SkinControl.SkinProgressBar();
            this.trackBarSound = new System.Windows.Forms.TrackBar();
            this.soundVol = new System.Windows.Forms.Button();
            this.timerPlay = new System.Windows.Forms.Timer(this.components);
            this.videoContextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.panel2 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.video)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSound)).BeginInit();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // video
            // 
            this.video.BackColor = System.Drawing.Color.Transparent;
            this.video.ContextMenuStrip = this.videoContextMenuStrip;
            this.video.Dock = System.Windows.Forms.DockStyle.Fill;
            this.video.Location = new System.Drawing.Point(0, 0);
            this.video.Name = "video";
            this.video.Size = new System.Drawing.Size(800, 423);
            this.video.TabIndex = 0;
            this.video.TabStop = false;
            // 
            // openFileDlg
            // 
            this.openFileDlg.FileName = "openFileDlg";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 25);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开ToolStripMenuItem});
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(44, 21);
            this.文件ToolStripMenuItem.Text = "文件";
            // 
            // 打开ToolStripMenuItem
            // 
            this.打开ToolStripMenuItem.Name = "打开ToolStripMenuItem";
            this.打开ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.打开ToolStripMenuItem.Text = "打开";
            this.打开ToolStripMenuItem.Click += new System.EventHandler(this.open_ToolStripMenuItem_Click);
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Location = new System.Drawing.Point(69, 16);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(83, 12);
            this.timeLabel.TabIndex = 5;
            this.timeLabel.Text = "10:10 / 56:12";
            // 
            // playOrPause
            // 
            this.playOrPause.Location = new System.Drawing.Point(38, 13);
            this.playOrPause.Name = "playOrPause";
            this.playOrPause.Size = new System.Drawing.Size(25, 21);
            this.playOrPause.TabIndex = 6;
            this.playOrPause.UseVisualStyleBackColor = true;
            this.playOrPause.Click += new System.EventHandler(this.PlayOrPause_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.progressBar);
            this.panel1.Controls.Add(this.trackBarSound);
            this.panel1.Controls.Add(this.soundVol);
            this.panel1.Controls.Add(this.playOrPause);
            this.panel1.Controls.Add(this.timeLabel);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point(0, 448);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(800, 37);
            this.panel1.TabIndex = 7;
            // 
            // progressBar
            // 
            this.progressBar.Back = null;
            this.progressBar.BackColor = System.Drawing.Color.Transparent;
            this.progressBar.BarBack = null;
            this.progressBar.BarRadiusStyle = CCWin.SkinClass.RoundStyle.All;
            this.progressBar.Dock = System.Windows.Forms.DockStyle.Top;
            this.progressBar.ForeColor = System.Drawing.Color.Red;
            this.progressBar.Location = new System.Drawing.Point(0, 0);
            this.progressBar.Name = "progressBar";
            this.progressBar.RadiusStyle = CCWin.SkinClass.RoundStyle.All;
            this.progressBar.Size = new System.Drawing.Size(800, 10);
            this.progressBar.TabIndex = 10;
            this.progressBar.MouseClick += new System.Windows.Forms.MouseEventHandler(this.ProgressBar_MouseClick);
            // 
            // trackBarSound
            // 
            this.trackBarSound.Location = new System.Drawing.Point(649, 12);
            this.trackBarSound.Name = "trackBarSound";
            this.trackBarSound.Size = new System.Drawing.Size(139, 45);
            this.trackBarSound.TabIndex = 9;
            this.trackBarSound.Scroll += new System.EventHandler(this.TrackBarSound_Scroll);
            // 
            // soundVol
            // 
            this.soundVol.Location = new System.Drawing.Point(618, 12);
            this.soundVol.Name = "soundVol";
            this.soundVol.Size = new System.Drawing.Size(25, 21);
            this.soundVol.TabIndex = 8;
            this.soundVol.UseVisualStyleBackColor = true;
            this.soundVol.Click += new System.EventHandler(this.SoundVol_Click);
            // 
            // timerPlay
            // 
            this.timerPlay.Tick += new System.EventHandler(this.TimerPlay_Tick);
            // 
            // videoContextMenuStrip
            // 
            this.videoContextMenuStrip.Name = "videoContextMenuStrip";
            this.videoContextMenuStrip.Size = new System.Drawing.Size(61, 4);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.video);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(0, 25);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(800, 423);
            this.panel2.TabIndex = 9;
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(800, 485);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.Location = new System.Drawing.Point(960, 0);
            this.Name = "Main";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Bitplayer";
            this.Load += new System.EventHandler(this.Main_Load);
            ((System.ComponentModel.ISupportInitialize)(this.video)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSound)).EndInit();
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox video;
        private System.Windows.Forms.OpenFileDialog openFileDlg;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 打开ToolStripMenuItem;
        private System.Windows.Forms.Label timeLabel;
        private System.Windows.Forms.Button playOrPause;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button soundVol;
        private System.Windows.Forms.Timer timerPlay;
        private System.Windows.Forms.TrackBar trackBarSound;
        private CCWin.SkinControl.SkinProgressBar progressBar;
        private System.Windows.Forms.ContextMenuStrip videoContextMenuStrip;
        private System.Windows.Forms.Panel panel2;
    }
}

