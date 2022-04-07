#include "LoginZone.h"

void LoginZone::toJson()
{

}

LoginZone::LoginZone(int timeStamp, std::string idUser, std::string idGame, int z, bool comp)
	:TrackerEvent(timeStamp, idUser, idGame), zone(z), completed(comp)
{
	_event = eventype::LoginZone;
}
