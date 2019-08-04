#ifndef PLAYER_H_
#define PLAYER_H_
#include"PlayerCore.h"
#include<Windows.h>
namespace LeoPlayer {
	
	class Player
	{
	public:
		Player() {};
		virtual ~Player(){}



		/**
		*  重置player的初始化状态
		*/
		virtual void Reset() = 0;

		/**
		*  释放player
		*/
		virtual void ReleasePlayer() = 0;

		/**
		 *  设置播放源的URL地址
		 *
		 *  @param url 播放地址
		 */
		virtual void SetDataSource(const char* url) = 0;

		/**
		 *  开始播放
		 */
		virtual void Start() =0;

		/**
		*  停止播放
		*/
		virtual void Stop()=0;

		/**
		*  暂停播放
		*/
		virtual void Pause()=0;

		/**
		*   获取视频的宽度
		*
		*  @return 返回视频宽度
		*/
		virtual int GetVideoWidth() = 0;
		/**
		*  获取视频高度
		*
		*  @return 返回视频高度
		*/
		virtual int GetVideoHeight() =0 ;

		/**
		*  判断视频是否正在播放
		*
		*  @return   如果正在播放bool值为true, 否则为false
		*/
		virtual bool IsPlaying() =0;

		/**
		*  寻求指定的时间位置
		*
		*  @param timeS 从开始到指定偏移的时间秒
		*/
		virtual void SeekTo(double timeS) = 0;

		/**
		*  获取当前播放位置
		*
		*  @return 当前位置以毫秒为单位
		*/
		virtual long GetCurrentPosition() = 0;

		/**
		*  获取视频文件的播放时长
		*
		*  @return 毫秒的时间
		*/
		virtual long GetDuration() = 0;

		/**
		*   设置该视频是否循环
		*
		*  @param loop 是否循环
		*/
		virtual void SetLooping(bool loop) = 0;

		/**
		*  检查是否循环播放
		*
		*  @return 如果循环播放bool值为true，否则为false
		*/
		virtual bool IsLooping() = 0;

		/**
		*   设置音量大小
		*
		*  @param volume 音量标量
		*/
		virtual void SetVolume(double volume) = 0;

		virtual void SetMute(bool mute) = 0;

		virtual double GetVolume() = 0;

		virtual void SetWindowId(int64_t data,bool isTexture=false) = 0;


		virtual void UpdatePlaybackInfo() = 0;

		virtual PlaybackInfo GetPlaybackInfo() = 0;

		virtual void ChangeNextAudio() = 0;

		virtual void ChangeNextSub() = 0;

		virtual void * GetMpvHandle()=0;

		virtual void GLRender(unsigned int fbo, int width, int height) =0;

		virtual unsigned int GetRedrawEvent() =0;

		virtual unsigned int GetMpvEvent()  =0;
		

	protected:
		PlayerCore m_playerCore;
		HANDLE     m_EventThreadHandle;
		std::string m_path;
		bool isPause;
		
	private:

	};

}

#endif // !PLAYER_H_
