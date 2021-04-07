#include "Cheats.h"
#include "Hooks.h"
#include "Teardown.h"

#include <Windows.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Time.h"

glm::vec3 newPos;
glm::vec3 exitSpeed;

glm::vec3 heightOffset(0.f, 1.7f, 0.f);

glm::quat newRotation;

int64_t lastRegisteredTime;

float lastHealth = 0.f;

/*
	FIXME
	 - Something related to noclip breaks collisions after a while, the player suddenly starts getting velocity out of nowhere, specially when colliding on the sides, and clips through things
	   despite not being on noclip
*/

void Cheats::Noclip::Toggle()
{
	Enabled = !Enabled;

	Hooks::PlayerHooks::doUpdateCamera = !Enabled;
	Hooks::PlayerHooks::doUpdateCollisions = !Enabled;

	if (!Enabled)
		Teardown::pGame->pPlayer->Velocity = exitSpeed;
	else
	{
		lastHealth = Teardown::pGame->pPlayer->Health;

		newPos = Teardown::pGame->pPlayer->cameraPosition2;
		lastRegisteredTime = Time::timeAsMilliseconds();
	}
}

void Cheats::Noclip::Run()
{
	if (!Enabled)
		return;

	if (Teardown::pGame->State != Teardown::gameState::playing || Teardown::pGame->pScene->pCurrentScreen || Teardown::pGame->pScene->pCurrentVehicle)
	{
		Toggle();
		return;
	}

	if (Teardown::pGame->isPaused)
		return;

	glm::vec2 input = Teardown::pGame->pPlayer->moveKeys;

	glm::quat qXAxis = glm::angleAxis(Teardown::pGame->pPlayer->totalMouseDelta.x, glm::vec3(1.f, 0, 0));
	glm::quat qYAxis = glm::angleAxis(Teardown::pGame->pPlayer->totalMouseDelta.y, glm::vec3(0, 1.f, 0));

	newRotation = qYAxis * qXAxis;
	Teardown::pGame->pPlayer->cameraRotation2 = newRotation;

	exitSpeed = glm::vec3(0, 0, 0);


	uint64_t timeDelta = Time::timeAsMilliseconds() - lastRegisteredTime;

	if (input.x != 0)
	{
		glm::vec3 fwdVec;

		fwdVec.x = 2 * (newRotation.x * newRotation.z + newRotation.w * newRotation.y);
		fwdVec.y = 2 * (newRotation.y * newRotation.z - newRotation.w * newRotation.x);
		fwdVec.z = 1 - 2 * (newRotation.x * newRotation.x + newRotation.y * newRotation.y);

		fwdVec *= input.x * (Speed * timeDelta / 10);

		if (GetAsyncKeyState(VK_SHIFT))
			fwdVec *= 2.f;

		if (GetAsyncKeyState(VK_LCONTROL))
			fwdVec *= 0.25f;

		newPos -= fwdVec;
		exitSpeed -= fwdVec;
	}

	if (input.y != 0)
	{
		glm::vec3 sideVec;

		sideVec.x = 1 - 2 * (newRotation.y * newRotation.y + newRotation.z * newRotation.z);
		sideVec.y = 2 * (newRotation.x * newRotation.y + newRotation.w * newRotation.z);
		sideVec.z = 2 * (newRotation.x * newRotation.z - newRotation.w * newRotation.y);

		sideVec *= input.y * (Speed * timeDelta / 10);

		if (GetAsyncKeyState(VK_SHIFT))
			sideVec *= 2.f;

		if (GetAsyncKeyState(VK_LCONTROL))
			sideVec *= 0.25f;

		newPos += sideVec;
		exitSpeed += sideVec;
	}

	exitSpeed *= (Teardown::pGame->pPlayer->cameraPosition2 - newPos).length() * timeDelta;

	Teardown::pGame->pPlayer->cameraPosition2 = newPos;
	Teardown::pGame->pPlayer->cameraPositionProcessed = newPos;

	Teardown::pGame->pPlayer->Position = newPos - heightOffset;

	lastRegisteredTime = Time::timeAsMilliseconds();

	Teardown::pGame->pPlayer->Health = lastHealth;
}