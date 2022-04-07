#include "Tracker.h"
#include "TrackerEvent.h"
#include "IPersistence.h"

Tracker* Tracker::instance;

IPersistence* Tracker::persistenceObject;

std::list<ITrackerAsset> Tracker::activeTrackers;



Tracker::Tracker() {

}

bool Tracker::Init(IPersistence* iPersistence)
{
	if (iPersistence != nullptr) {
		persistenceObject = iPersistence;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tracker::End()
{
	// TODO 
	//persistenceObject.flush();
	return false;
}

void Tracker::AddTrackEvent(TrackerEvent trackEvent)
{
	// std::find(activeTrackers.begin(), activeTrackers.end(), trackEvent);
	// TODO check que el evento es aceptado antes de enviarlo

	//persistenceObject.send(trackEvent);
}

Tracker* Tracker::GetInstance()
{
	if (instance != nullptr) {
		instance = new Tracker();
	}
	else {
		return instance;
	}
}
