#include "LogoutZone.h"
#include "jute.h"

std::string LogoutZone::toJson()
{
	TrackerEvent::commonJson();

	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_zone));
	mainJson.add_property("zone", num);

	jute::jValue aux(jute::jType::JNUMBER);
	aux.set_string(std::to_string((int)_next));
	mainJson.add_property("next", aux);

	return mainJson.to_string();
}

LogoutZone::LogoutZone() : TrackerEvent()
{
}

void LogoutZone::setZone(int zone)
{
	_zone = zone;
}

void LogoutZone::setNext(int next)
{
	_next = next;
}

int LogoutZone::getZone()
{
	return _zone;
}

int LogoutZone::getNext()
{	
	return _next;
}
