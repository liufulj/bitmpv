#include"stdafx.h"
#include "MPVController.h"
#include"PlayerCore.h"

namespace LeoPlayer {
	static inline void check_error(int status)
	{
		if (status < 0) {
			printf("mpv API error: %s\n", mpv_error_string(status));
			/*exit(1);*/
		}
	}
	MPVController::MPVController(PlayerCore *playerCore)
	{
	}


	MPVController::~MPVController()
	{

	}
	/**
	* mpv³õÊ¼»¯
	**/
	void MPVController::MPVInit()
	{
		mpv = mpv_create();
		mpvClientName = mpv_client_name(mpv);
		SetOptionString(MPVOption::Video::hwdec, "auto");
		//SetOptionString(MPVOption::OSD::osdLevel, "0");
		//SetOptionString(MPVOption::Video::vo, "direct3d");
		check_error(mpv_initialize(mpv));
		mpvVersion = GetString(MPVProperty::mpvVersion);


	}

	void MPVController::MPVQuit()
	{
		Command(MPVCommand::quit);
	}


	void MPVController::Command(MPVCommand command, std::string args[], int argc, bool checkerr)
	{
		if (mpv == NULL) {
			return;
		}
		if (argc > 0 && args[argc-1].c_str()==NULL){
			printf_s("doesnot need a null suffix");
		}
		int size = argc + 2;
		const char **argsc = new const char*[size];
		argsc[0] = command.cmd.c_str();
		for (int i = 0; i < argc; i++) {
				argsc[i+1] = args[i].c_str();
		}
		argsc[argc + 1] = NULL;
		int ret = mpv_command(mpv, argsc);
		if (checkerr) {
			check_error(ret);
		}
	}

	int MPVController::Command(std::string cmd)
	{
		return mpv_command_string(mpv,cmd.c_str());
	}
	void MPVController::SetFlag(std::string name, bool flag)
	{
		int data = flag ? 1 : 0;
		mpv_set_property(mpv, name.c_str(), MPV_FORMAT_FLAG, &data);
	}
	void MPVController::SetInt(std::string name, int value)
	{
		int64_t data = int64_t(value);
		mpv_set_property(mpv, name.c_str(), MPV_FORMAT_INT64, &data);
	}
	void MPVController::SetDouble(std::string name, double value)
	{
		double data = value;
		mpv_set_property(mpv, name.c_str(), MPV_FORMAT_DOUBLE, &data);
	}
	void MPVController::SetFlagAsync(std::string name, bool flag)
	{
		int data = flag ? 1 : 0;
		mpv_set_property_async(mpv, 0,name.c_str(), MPV_FORMAT_FLAG, &data);
	}
	void MPVController::SetIntAsync(std::string name, int value)
	{
		int64_t data = int64_t(value);
		mpv_set_property_async(mpv,0, name.c_str(), MPV_FORMAT_INT64, &data);
	}
	void MPVController::SetDoubleAsync(std::string name, double value)
	{
		double data = value;
		mpv_set_property_async(mpv,0, name.c_str(), MPV_FORMAT_DOUBLE, &data);
	}
	void MPVController::SetString(std::string name, std::string value)
	{
		mpv_set_property_string(mpv, name.c_str(), value.c_str());
	}
	bool MPVController::GetFlag(std::string name)
	{
		int64_t data = int64_t();
		mpv_get_property(mpv, name.c_str(), MPV_FORMAT_FLAG, &data);
		return data > 0;
	}
	int MPVController::GetInt(std::string name)
	{
		int64_t data = int64_t();
		mpv_get_property(mpv, name.c_str(), MPV_FORMAT_INT64, &data);
		return  (int) data;
	}
	double MPVController::GetDouble(std::string name)
	{
		double data = double();
		mpv_get_property(mpv, name.c_str(), MPV_FORMAT_DOUBLE, &data);
		return data;
	}
	std::string MPVController::GetString(std::string name)
	{
		char * cstr =mpv_get_property_string(mpv, name.c_str());
		if (cstr == NULL) {
			return std::string();
		}
		else {
			std::string str = std::string(cstr);
			mpv_free(cstr);
			return str;
		}
	}
	int MPVController::SetOptionInt(std::string name, int value, bool async)
	{
		int64_t i = int64_t(value);
		int code = mpv_set_option(mpv, name.c_str(), MPV_FORMAT_INT64, &i);
		return code;
	}
	int MPVController::SetOptionFloat(std::string name, float value, bool async)
	{
		double i = double(value);
		int code = mpv_set_option(mpv, name.c_str(), MPV_FORMAT_DOUBLE, &i);
		return code;
	}
	int MPVController::SetOptionBool(std::string name, bool value, bool async)
	{
		int code = mpv_set_option_string(mpv, name.c_str(), value ? "yes" : "no");
		return code;
	}
	int MPVController::SetOptionString(std::string name, std::string value, bool async)
	{
		int code = mpv_set_option_string(mpv, name.c_str(), value.c_str());
		return code;
	}
}

