#pragma once
#include <string>

class EventInfo
{
public:
	static const char* eventName[];

	enum class EventType : int
	{
		Login = 0,
		Logout = 1,
		LoginZone = 2,
		LogoutZone = 3,
		OpenInv = 4,
		OpenSkills = 5,
		OpenChest = 6,
		OpenShop = 7,
		UseSkill = 8,
		UsePot = 9,
		TutoTask = 10,

		NUM_EVENTS = 11,
		NONE = 100
	};
};

