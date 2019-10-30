#pragma once
#include "Player.h"
struct mpv_render_context;
namespace LeoPlayer {

	class WinPlayer :public Player
	{
	public:
		WinPlayer();
		~WinPlayer();
		/**
		*  重置player的初始化状态
		*/
		virtual void Reset()override;

		/**
		*  释放player
		*/
		virtual void ReleasePlayer()override;

		/**
		 *  设置播放源的URL地址
		 *
		 *  @param url 播放地址
		 */
		virtual void SetDataSource(const char* url)override;

		/**
		 *  开始播放
		 */
		virtual void Start()override;

		/**
		*  停止播放
		*/
		virtual void Stop()override;

		/**
		*  暂停播放
		*/
		virtual void Pause()override;

		/**
		*   获取视频的宽度
		*
		*  @return 返回视频宽度
		*/
		virtual int GetVideoWidth()override;
		/**
		*  获取视频高度
		*
		*  @return 返回视频高度
		*/
		virtual int GetVideoHeight()override;

		/**
		*  判断视频是否正在播放
		*
		*  @return   如果正在播放bool值为true, 否则为false
		*/
		virtual bool IsPlaying()override;

		/**
		*  寻求指定的时间位置
		*
		*  @param timeS 从开始到指定偏移的时间秒
		*/
		virtual void SeekTo(double timeS)override;

		/**
		*  获取当前播放位置
		*
		*  @return 当前位置以秒为单位
		*/
		virtual long GetCurrentPosition()override;

		/**
		*  获取视频文件的播放时长
		*
		*  @return 秒的时间
		*/
		virtual long GetDuration()override;

		/**
		*   设置该视频是否循环
		*
		*  @param loop 是否循环
		*/
		virtual void SetLooping(bool loop)override;

		/**
		*  检查是否循环播放
		*
		*  @return 如果循环播放bool值为true，否则为false
		*/
		virtual bool IsLooping()override;

		/**
		*   设置音量大小
		*
		*  @param volume 音量标量
		*/
		virtual void SetVolume(double volume)override;

		virtual void SetMute(bool mute)override;

		virtual double GetVolume()override;

		virtual void SetWindowId(int64_t data, bool isTexture = false)override;

		virtual void UpdatePlaybackInfo() override;

		virtual PlaybackInfo GetPlaybackInfo() override;

		virtual void SetTrack(MPVTrack::TrackType type, int index) override;

		virtual void ChangeNextAudio() override;

		virtual void ChangeNextSub() override;

		virtual  void * GetMpvHandle() override;

		virtual void GLRender(unsigned int fbo,int width, int height) override;

		virtual unsigned int GetRedrawEvent() override;

		virtual unsigned int GetMpvEvent()  override;

		virtual void InitGL() override;
	private:
		void InitSDL();
		bool mDraw;
		mpv_render_context *mpv_gl;
		static unsigned int  wakeup_on_mpv_redraw;
		static unsigned int  wakeup_on_mpv_events;
		static void* get_proc_address_mpv(void *fn_ctx, const char*name);
		static void on_mpv_events(void *ctx);
		static void on_mpv_redraw(void *ctx);
	};

}