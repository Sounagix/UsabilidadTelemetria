#include "UseSkill.h"

std::string UseSkill::toJson()
{
	TrackerEvent::commonJson();

	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_zone));
	mainJson.add_property("zone", num);

	return mainJson.to_string();
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
