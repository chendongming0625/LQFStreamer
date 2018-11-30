/**********************************************
*Date:  2018��9��21��
*Description: ����Ƶ��������ֻ�ܲ�����Ƶ��
**********************************************/

#include <iostream>
#ifdef _WIN32
#include <Winsock2.h>
#endif

#include "LogUtil.h"
using namespace std;

int InitSockets()
{
#ifdef _WIN32
	WORD version;
	WSADATA wsaData;
	version = MAKEWORD(2, 2);
	return (WSAStartup(version, &wsaData) == 0);
#endif
}

void CleanupSockets()
{
#ifdef _WIN32
	WSACleanup();
#endif
}


extern int simple_player_test(int argc, char *argv[]);
int RTP_PlayerTest(int argc, char *argv[]);
#undef main
int main(int argc, char *argv[])
{
	LogInit("rtp.txt");
	InitSockets();

	int ret = 0;
// 	if (simple_player_test(argc, argv) < 0)
// 	{
// 		printf("simple_player_test failed\n");
// 	}
	if (RTP_PlayerTest(argc, argv) < 0)
	{
		printf("RTP_PlayerTest failed\n");
	}
	LogDeinit();
	CleanupSockets();

	system("pause");
	
	return 0;
}