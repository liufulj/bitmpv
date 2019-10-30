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
		*  ����player�ĳ�ʼ��״̬
		*/
		virtual void Reset()override;

		/**
		*  �ͷ�player
		*/
		virtual void ReleasePlayer()override;

		/**
		 *  ���ò���Դ��URL��ַ
		 *
		 *  @param url ���ŵ�ַ
		 */
		virtual void SetDataSource(const char* url)override;

		/**
		 *  ��ʼ����
		 */
		virtual void Start()override;

		/**
		*  ֹͣ����
		*/
		virtual void Stop()override;

		/**
		*  ��ͣ����
		*/
		virtual void Pause()override;

		/**
		*   ��ȡ��Ƶ�Ŀ��
		*
		*  @return ������Ƶ���
		*/
		virtual int GetVideoWidth()override;
		/**
		*  ��ȡ��Ƶ�߶�
		*
		*  @return ������Ƶ�߶�
		*/
		virtual int GetVideoHeight()override;

		/**
		*  �ж���Ƶ�Ƿ����ڲ���
		*
		*  @return   ������ڲ���boolֵΪtrue, ����Ϊfalse
		*/
		virtual bool IsPlaying()override;

		/**
		*  Ѱ��ָ����ʱ��λ��
		*
		*  @param timeS �ӿ�ʼ��ָ��ƫ�Ƶ�ʱ����
		*/
		virtual void SeekTo(double timeS)override;

		/**
		*  ��ȡ��ǰ����λ��
		*
		*  @return ��ǰλ������Ϊ��λ
		*/
		virtual long GetCurrentPosition()override;

		/**
		*  ��ȡ��Ƶ�ļ��Ĳ���ʱ��
		*
		*  @return ���ʱ��
		*/
		virtual long GetDuration()override;

		/**
		*   ���ø���Ƶ�Ƿ�ѭ��
		*
		*  @param loop �Ƿ�ѭ��
		*/
		virtual void SetLooping(bool loop)override;

		/**
		*  ����Ƿ�ѭ������
		*
		*  @return ���ѭ������boolֵΪtrue������Ϊfalse
		*/
		virtual bool IsLooping()override;

		/**
		*   ����������С
		*
		*  @param volume ��������
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