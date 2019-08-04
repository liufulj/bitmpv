#ifndef MPV_CONTROLLER_H_
#define MPV_CONTROLLER_H_
#include<string>
extern "C" {
#include "Client.h"
}
struct MPVCommand;
namespace LeoPlayer {

	class PlayerCore;
	class MPVController
	{
	public:
		MPVController(PlayerCore *playerCore);
		MPVController() {}
		~MPVController();
		void MPVInit();
		void MPVQuit();
	   //send mpv command
		void Command(MPVCommand cmd, std::string argv[]=NULL, int argc=0, bool checkerr = true);
		int Command(std::string cmd);

		//property
		void SetFlag(std::string name, bool flag);
		void SetInt(std::string name, int value);
		void SetDouble(std::string name, double value);
		void SetFlagAsync(std::string name, bool flag);
		void SetIntAsync(std::string name, int value);
		void SetDoubleAsync(std::string name, double value);
        void SetString(std::string name, std::string value);
		bool GetFlag(std::string name);
		int  GetInt(std::string name);
		double GetDouble(std::string name);
		std::string GetString(std::string name);

		//option
		int SetOptionInt(std::string name,int value,bool async = false);
		int SetOptionFloat(std::string name, float value, bool async = false);
		int SetOptionBool(std::string name, bool value, bool async = false);
		int SetOptionString(std::string name, std::string value, bool async = false);

		mpv_handle * GetMPVHandle() {
			return mpv;
		};
		



	private:
		mpv_handle * mpv;
		const char *mpvClientName;
		std::string mpvVersion;
		PlayerCore *player;
	
	};
}
#endif
