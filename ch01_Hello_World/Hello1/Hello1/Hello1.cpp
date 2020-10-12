// Hello1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "tchar.h"
#include <aced.h> //ARX应用程序定义和AutoCAD指定服务所需要的头文件
#include <rxregsvc.h>//使用acrxXXX工具函数所需要的头文件

void InitApp();
void UnloadApp();

void HelloWorld();
void InitApp()
{
	//使用AutoCAD命令机制注册一个新命令
	acedRegCmds->addCommand(_T("Hello1"),_T("Hello"),_T("Hello"),ACRX_CMD_MODAL,HelloWorld);
}

void UnloadApp()
{
//删除命令组
	acedRegCmds->removeGroup(_T("Hello1"));
}
void HelloWorld()
{
	acutPrintf(_T("\nHello, World!"));
}

//入口点函数
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
		case AcRx::kInitAppMsg:
			acrxDynamicLinker->unlockApplication(pkt);
			acrxRegisterAppMDIAware(pkt);
			InitApp();
			break;
		case AcRx::kUnloadAppMsg:
			UnloadApp();
			break;
		default:
			break;
	}
	return AcRx::kRetOK;
}
