#include "UseSkill.h"

std::string UseSkill::toJson()
{
	return " ";
}

void UseSkill::setZone(int zone)
{
	_zone = zone;
}

int UseSkill::getZone()
{
	return _zone;
}

UseSkill::UseSkill() :TrackerEvent() {}
