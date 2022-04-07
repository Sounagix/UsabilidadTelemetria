#include "OpenChest.h"

void OpenChest::toJson()
{
}

OpenChest::OpenChest(int timeStamp, std::string idUser, std::string idGame, bool openInv)
	:TrackerEvent(timeStamp, idUser, idGame),_openInv(openInv)
{
	_event = eventype::OpenChest;
}
