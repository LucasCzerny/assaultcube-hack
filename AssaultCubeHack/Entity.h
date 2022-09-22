#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>

#include "vec.h"

// Created with ReClass.NET 1.2 by KN4CK3R

#define MACRO_CONCAT_HELPER(a,b) a##b
#define MACRO_CONCAT(a,b) MACRO_CONCAT_HELPER(a,b)

#define PADDING(x) char MACRO_CONCAT(pad_, __LINE__)[x]

class Entity
{
public:
	PADDING(4);

	vec3 HeadPosition;
	vec3 Velocity;

	PADDING(24);

	vec3 FeetPosition;
	vec2 ViewAngles;

	PADDING(40);

	int32_t isIdle;

	PADDING(132);

	int32_t Health;
	int32_t Armor;

	PADDING(292);

	bool bAttack;

	char Name[16];

	PADDING(247);

	int32_t Team;

	PADDING(8);

	int32_t State;

	PADDING(56);

	class Weapon* CurrentWeaponPointer;
};


class Weapon
{
public:
	PADDING(4);

	int32_t WeaponID;
	class Entity* Owner;
	class WeaponName* WeaponNamePointer;
	class WeaponState* WeaponStatePointer;

	PADDING(8);

	int32_t ShotsFired;
};

class WeaponName
{
public:
	char Name[16];
};

class WeaponState
{
public:
	int32_t AmmoInMag;

	PADDING(36);

	int32_t AmmoInClip;

	PADDING(280);
};

Entity* Get();