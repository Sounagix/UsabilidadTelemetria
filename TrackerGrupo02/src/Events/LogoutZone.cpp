#include "LogoutZone.h"

void LogoutZone::toJson()
{

}

LogoutZone::LogoutZone(int time, string idu, string idg, int z, bool comp)
	:TrackerEvent(timestamp, idu, idg), zone(z), completed(comp)
{
	ev = eventype::LogoutZone;
}
