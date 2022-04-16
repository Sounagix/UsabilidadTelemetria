#pragma once
#include "ITrackerAsset.h"
#include "IPersistence.h"
#include <list>
#include <iostream>

enum class PersistenceType {
	FILE = 0,
	SERVER = 1
};

class TrackerEvent;

class Tracker
{
private:
	static Tracker* _instance;
	static IPersistence* _persistenceObject;
	static std::list<ITrackerAsset> _activeTrackers;

	Tracker();
public:
	/// <summary>
	/// Inicializa el singleton del Tracker
	/// </summary>
	/// <param name="iPersistence"></param>
	/// <returns></returns>
	static bool Init(PersistenceType persistType = PersistenceType::FILE, TypeOfFile fileType = TypeOfFile::Json, std::string pathFile = "");
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
	/// <summary>
	/// Limpia la basura del tracker
	/// </summary>
	static void Free();
	/// <summary>
	/// Calcula el timeStamp y lo devuelve como int
	/// </summary>
	/// <returns></returns>
	static int GetTimeStamp();
};

