#include "OpenSkills.h"

std::string OpenSkills::toJson()
{
	TrackerEvent::commonJson();

	jute::jValue num(jute::jType::JBOOLEAN);
	num.set_string(std::to_string((bool)_points));
	mainJson.add_property("points", num);

	

	return mainJson.to_string();
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
