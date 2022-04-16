#include "OpenInv.h"
#include "jute.h"

std::string OpenInv::toJson()
{
	TrackerEvent::commonJson();
	
	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_timeOut));
	mainJson.add_property("timeOut", num);

	jute::jValue booolean(jute::jType::JBOOLEAN);
	booolean.set_string(std::to_string((bool)_equipPot));
	mainJson.add_property("equipPot", booolean);

	return mainJson.to_string();
}

OpenInv::OpenInv() :TrackerEvent() {}

void OpenInv::setTimeOut(long long timeOut)
{
	_timeOut = timeOut;
}

void OpenInv::setEquipPot(bool equipPot)
{
	_equipPot = equipPot;
}

long long OpenInv::getTimeOut()
{
	return _timeOut;
}

bool OpenInv::getEquipPot()
{
	return _equipPot;
}