#include "LoginZone.h"
#include "jute.h"

std::string LoginZone::toJson()
{
	return " ";
}

LoginZone::LoginZone() : TrackerEvent() {}

void LoginZone::setZone(int zone)
{
	_zone = zone;
}

void LoginZone::setCompleted(bool completed)
{
	_completed = completed;
}

int LoginZone::getZone()
{
	return _zone;
}

bool LoginZone::getCompleted()
{
	return 	_completed;
}
