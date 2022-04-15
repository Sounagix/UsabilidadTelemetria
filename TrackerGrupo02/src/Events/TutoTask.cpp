#include "TutoTask.h"

std::string TutoTask::toJson()
{
	TrackerEvent::commonJson();


	jute::jValue aux(jute::jType::JSTRING);
	aux.set_string(_name);
	mainJson.add_property("name", aux);

	jute::jValue num(jute::jType::JNUMBER);
	num.set_string(std::to_string((int)_timeOut));
	mainJson.add_property("timeOut", num);

	return mainJson.to_string();
}

void TutoTask::setName(std::string name)
{
	_name = name;
}

void TutoTask::setTimeOut(int t)
{
	_timeOut = t;
}

std::string TutoTask::getName()
{
	return _name;
}

TutoTask::TutoTask() :TrackerEvent() {}
