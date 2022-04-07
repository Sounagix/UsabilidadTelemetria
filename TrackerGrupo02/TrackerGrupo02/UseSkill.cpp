#include "UseSkill.h"

void UseSkill::toJson()
{
}

UseSkill::UseSkill(int timeStamp, std::string idUser, std::string idGame, int zone)
	:TrackerEvent(timeStamp, idUser, idGame),_zone(zone)
{
	_event = eventype::UseSkill;
}
