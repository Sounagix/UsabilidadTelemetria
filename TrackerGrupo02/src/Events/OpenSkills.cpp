#include "OpenSkills.h"

std::string OpenSkills::toJson()
{
	return " ";
}

OpenSkills::OpenSkills() :TrackerEvent() {}

void OpenSkills::setPoints(bool points)
{
	_points = points;
}

bool OpenSkills::getPoints()
{
	return _points;
}
