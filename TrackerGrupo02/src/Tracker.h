#pragma once
#include <list>
#include <iostream>
#include "ITrackerAsset.h"
#include "IPersistence.h"

enum class PersistenceType {
	FILE = 0,
	SERVER = 1
};

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
	static bool Init(PersistenceType persistType = PersistenceType::FILE, TypeOfFile fileType = TypeOfFile::Json);
	/// <summary>
	/// Realiza el volcado de los datos que esten en la cola
	/// </summary>
	/// <returns></returns>
	static bool End();
	/// <summary>
	/// Envia un evento nuevo al tracker
	/// </summary>
	/// <param name="newEvent">Nuevo evento que se a va a anadir</param>
	static void TrackEvent(TrackerEvent* newEvent);
	/// <summary>
	/// Factoria de eventos
	/// </summary>
	static TrackerEvent* CreateNewEvent(int timeStamp, std::string idUser, std::string idGame, int eType);
	/// <summary>
	/// Devuelve la instancia del tracker
	/// </summary>
	static Tracker* GetInstance();
};

