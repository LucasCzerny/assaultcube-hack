#include "Internal.h"
#include "Entity.h"

struct Values
{
	bool TriggerBotToggle;
	bool AimBotToggle;
	bool GodModeToggle;

	bool operator!=(const Values& other)
	{
		return TriggerBotToggle != other.TriggerBotToggle || AimBotToggle != other.AimBotToggle || GodModeToggle != other.GodModeToggle;
	}
} values;

void WINAPI InternalHack::HackThread(HMODULE hModule)
{
	InternalHack::CreateConsole();
		
	Entity* localPlayer = Get();

	ValueTracker<Values> tracker;

	while (!KeyDown(VK_F1))
	{
		tracker.Update(values, [&]()
		{
			std::cout << "[F1] Unload module\n";
			std::cout << "[F2] TriggerBot (" << (values.TriggerBotToggle ? "Enabled" : "Disabled") <<")\n";
			std::cout << "[F3] AimBot (" << (values.AimBotToggle ? "Enabled" : "Disabled") <<")\n";
			std::cout << "[F4] GodMode (" << (values.GodModeToggle ? "Enabled" : "Disabled") <<")\n";
		});

		if (KeyDown(VK_F2))
			values.TriggerBotToggle = !values.TriggerBotToggle;

		if (KeyDown(VK_F3))
			values.AimBotToggle = !values.AimBotToggle;
		
		if (KeyDown(VK_F4))
			values.GodModeToggle = !values.GodModeToggle;

		if (values.TriggerBotToggle)
		{
			Entity* crossHairEntity = GetCrossHairEntity();

			if (crossHairEntity != nullptr)
			{
				localPlayer->bAttack = (int32_t)(crossHairEntity->Team != localPlayer->Team);
			}
			else
			{
				localPlayer->bAttack = 0;
			}
		}

		if (values.AimBotToggle)
		{
			vec3 localPlayerHeadPosition = localPlayer->HeadPosition;

			Entity* closestEntity = nullptr;
			float shortestDistance = 10000000000000000.0f;

			for (int i = 1; i < 30; i++)
			{
				Entity* currentEntity = GetEntityAtIndex(i);

				if (*(int32_t*)currentEntity)
				{
					if (currentEntity->Team != localPlayer->Team &&
						currentEntity->State == 0 &&
						IsVisible(localPlayer, currentEntity))
					{
						vec3 currentHeadPosition = currentEntity->HeadPosition;
						vec3 direction = currentHeadPosition - localPlayerHeadPosition;

						float distance = direction.magnitude();

						if (distance < shortestDistance)
						{
							shortestDistance = distance;
							closestEntity = currentEntity;
						}
					}
				}
			}

			if (closestEntity)
			{
				vec3 closestEntityHeadPosition = closestEntity->HeadPosition;
				vec3 direction = closestEntityHeadPosition - localPlayerHeadPosition;

				float jaw = -atan2f(direction.x, direction.y) / PI * 180.0f + 180.0f;
				float pitch = asinf(direction.z / vec3(direction.x, direction.y, 0.0f).magnitude()) * (180.0f / PI);

				localPlayer->ViewAngles.x = jaw;
				localPlayer->ViewAngles.y = pitch;
			}
		}

		if (values.GodModeToggle)
		{
			localPlayer->Health = 6969;
			localPlayer->CurrentWeaponPointer->WeaponStatePointer->AmmoInClip = 6969;
		}

		Sleep(1);
	}

	InternalHack::DestroyConsole();
	InternalHack::Exit(hModule);
}