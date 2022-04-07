#include "OpenShop.h"

void OpenShop::toJson()
{

}

OpenShop::OpenShop(int timeStamp, std::string idUser, std::string idGame)
	:TrackerEvent(timeStamp, idUser, idGame)
{
	_event = eventype::OpenShop;
}
