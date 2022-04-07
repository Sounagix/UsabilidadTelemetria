#pragma once
#include <list>
#include "ITrackerAsset.h"

enum class PersistenceType {
	FILE = 0,
	SERVER = 1
};

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
	/// <summary>
	/// Inicializa el singleton del Tracker
	/// </summary>
	/// <param name="iPersistence"></param>
	/// <returns></returns>
	static bool Init(PersistenceType persitType);

	static bool End();

	static void TrackEvent();

	static Tracker* GetInstance();
};

