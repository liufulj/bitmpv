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
		*  ����player�ĳ�ʼ��״̬
		*/
		virtual void Reset() = 0;

		/**
		*  �ͷ�player
		*/
		virtual void ReleasePlayer() = 0;

		/**
		 *  ���ò���Դ��URL��ַ
		 *
		 *  @param url ���ŵ�ַ
		 */
		virtual void SetDataSource(const char* url) = 0;

		/**
		 *  ��ʼ����
		 */
		virtual void Start() =0;

		/**
		*  ֹͣ����
		*/
		virtual void Stop()=0;

		/**
		*  ��ͣ����
		*/
		virtual void Pause()=0;

		/**
		*   ��ȡ��Ƶ�Ŀ��
		*
		*  @return ������Ƶ���
		*/
		virtual int GetVideoWidth() = 0;
		/**
		*  ��ȡ��Ƶ�߶�
		*
		*  @return ������Ƶ�߶�
		*/
		virtual int GetVideoHeight() =0 ;

		/**
		*  �ж���Ƶ�Ƿ����ڲ���
		*
		*  @return   ������ڲ���boolֵΪtrue, ����Ϊfalse
		*/
		virtual bool IsPlaying() =0;

		/**
		*  Ѱ��ָ����ʱ��λ��
		*
		*  @param timeS �ӿ�ʼ��ָ��ƫ�Ƶ�ʱ����
		*/
		virtual void SeekTo(double timeS) = 0;

		/**
		*  ��ȡ��ǰ����λ��
		*
		*  @return ��ǰλ���Ժ���Ϊ��λ
		*/
		virtual long GetCurrentPosition() = 0;

		/**
		*  ��ȡ��Ƶ�ļ��Ĳ���ʱ��
		*
		*  @return �����ʱ��
		*/
		virtual long GetDuration() = 0;

		/**
		*   ���ø���Ƶ�Ƿ�ѭ��
		*
		*  @param loop �Ƿ�ѭ��
		*/
		virtual void SetLooping(bool loop) = 0;

		/**
		*  ����Ƿ�ѭ������
		*
		*  @return ���ѭ������boolֵΪtrue������Ϊfalse
		*/
		virtual bool IsLooping() = 0;

		/**
		*   ����������С
		*
		*  @param volume ��������
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
