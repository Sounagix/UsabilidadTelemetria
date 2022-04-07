#include "Tracker.h"
#include "TrackerEvent.h"
#include "IPersistence.h"

Tracker* Tracker::instance;

IPersistence* Tracker::persistenceObject;

std::list<ITrackerAsset> Tracker::activeTrackers;



Tracker::Tracker() {

}

bool Tracker::Init(PersistenceType persistType)
{
	if (persistenceObject != nullptr) {
		switch (persistType)
		{
		case PersistenceType::FILE:
			// TODO: Crearlo de forma FILE
			//persistenceObject = new IPersistence();
			break;
		case PersistenceType::SERVER:
			break;
		default:
			break;
		}
		
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

void Tracker::TrackEvent(/*Aqui se incluyen los parametros del evento que se va a crear */)
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
