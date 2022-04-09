#include "TutoTask.h"

std::string TutoTask::toJson()
{
	return " ";
}

void TutoTask::setName(std::string name)
{
	_name = name;
}

std::string TutoTask::getName()
{
	return _name;
}

TutoTask::TutoTask() :TrackerEvent() {}
