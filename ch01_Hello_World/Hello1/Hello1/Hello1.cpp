// Hello1.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "tchar.h"
#include <aced.h> //ARXӦ�ó������AutoCADָ����������Ҫ��ͷ�ļ�
#include <rxregsvc.h>//ʹ��acrxXXX���ߺ�������Ҫ��ͷ�ļ�

void InitApp();
void UnloadApp();

void HelloWorld();
void InitApp()
{
	//ʹ��AutoCAD�������ע��һ��������
	acedRegCmds->addCommand(_T("Hello1"),_T("Hello"),_T("Hello"),ACRX_CMD_MODAL,HelloWorld);
}

void UnloadApp()
{
//ɾ��������
	acedRegCmds->removeGroup(_T("Hello1"));
}
void HelloWorld()
{
	acutPrintf(_T("\nHello, World!"));
}

//��ڵ㺯��
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
