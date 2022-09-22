#include "Entity.h"

Entity* Get()
{
	uintptr_t moduleHandle = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	static Entity** player = (Entity**)(moduleHandle + 0x10F4F4);
	return *player;
}