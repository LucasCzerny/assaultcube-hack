#pragma once

#include "Dependencies.h"

class InternalHack
{
public:
	static void WINAPI HackThread(HMODULE hModule);

	static void CreateConsole()
	{
		AllocConsole();
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	}

	static void DestroyConsole()
	{
		fclose((FILE*)stdout);
		FreeConsole();
	}

	static void Exit(HMODULE hModule)
	{
		FreeLibraryAndExitThread(hModule, 0);
	}

	static bool KeyDown(int32_t keyCode)
	{
		return GetAsyncKeyState(keyCode) & 1;
	}
};

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)InternalHack::HackThread, hModule, 0, 0);
			if (hThread)
			{
				CloseHandle(hThread);
			}
		}
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}

	return TRUE;
}