#include "LoginZone.h"

void LoginZone::toJson()
{

}

LoginZone::LoginZone(int time, string idu, string idg,int z ,bool comp) 
:TrackerEvent(timestamp, idu, idg) ,zone(z),completed(comp)
{
	ev = eventype::LoginZone;	
}
