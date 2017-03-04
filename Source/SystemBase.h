#pragma once
#include <string>
//系统基类
class CSystemBase
{
public:
	//初始化
	virtual int Initialize() = 0;
	//更新
	virtual int Update(double time_step) = 0;
	//终止
	virtual int Terminate() = 0;

private:
};

enum SYSTEM_ACTIVITY_STATUS
{
	SYSTEM_ACTIVITY_SUCCEED = 0,
	SYSTEM_ACTIVITY_FAILED
};