#include "LogoutZone.h"
#include "jute.h"

std::string LogoutZone::toJson()
{
	return " ";
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
