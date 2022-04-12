#include "Login.h"
std::string Login::toJson()
{
	TrackerEvent::commonJson();
	return mainJson.to_string();
}

Login::Login() :TrackerEvent() {}
