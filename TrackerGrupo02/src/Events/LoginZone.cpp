#include "LoginZone.h"
#include "jute.h"

std::string LoginZone::toJson()
{
	TrackerEvent::commonJson();

	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_zone));
	mainJson.add_property("zone", num);

	jute::jValue aux(jute::jType::JBOOLEAN);
	aux.set_string(std::to_string((bool)_completed));
	mainJson.add_property("completed", aux);

	return mainJson.to_string();
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
