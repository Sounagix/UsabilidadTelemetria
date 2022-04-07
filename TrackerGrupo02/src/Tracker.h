#pragma once
#include <list>
#include "ITrackerAsset.h"


class IPersistence;
class ITrackerAsset;
class TrackerEvent;

class Tracker
{
private:
	static Tracker* instance;
	static IPersistence* persistenceObject;
	static std::list<ITrackerAsset> activeTrackers;

	Tracker();

public:
	
	static bool Init(IPersistence* iPersistence);

	static bool End();

	static void AddTrackEvent(TrackerEvent trackEvent);

	static Tracker* GetInstance();
};

