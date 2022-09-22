#pragma once

#include <Windows.h>
#include <TlHelp32.h>

#include "Entity.h"

typedef int(*GetCrossHairEntityFunc)(void);
typedef int(*TraceLinefunc)(float*, float*);

uintptr_t ModuleHandle()
{
	static uintptr_t moduleHandle = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	return moduleHandle;
}

Entity* GetEntityAtIndex(int i)
{
	static uintptr_t entityList = *(uintptr_t*)(ModuleHandle() + 0x10F4F8);
	Entity* entity = *(Entity**)(entityList + 0x4 * i);

	return entity;
}

struct traceresult_s
{
    vec3 end;
    bool collided;
};

bool IsVisible(Entity* localPlayer, Entity* enemy)
{
    DWORD traceLine = 0x048a310;
    traceresult_s traceresult;
    traceresult.collided = false;
    vec3 from = localPlayer->HeadPosition;
    vec3 to = enemy->HeadPosition;

    __asm
    {
        push 0; bSkipTags
        push 0; bCheckPlayers
        push localPlayer
        push to.z
        push to.y
        push to.x
        push from.z
        push from.y
        push from.x
        lea eax, [traceresult]
        call traceLine;
        add esp, 36
    }

    return !traceresult.collided;
}

Entity* GetCrossHairEntity()
{
	static GetCrossHairEntityFunc getCrossHairEntityFunc = (GetCrossHairEntityFunc)(ModuleHandle() + 0x607c0);
	Entity* crossHairEntity = (Entity*)getCrossHairEntityFunc();

	return crossHairEntity;
}