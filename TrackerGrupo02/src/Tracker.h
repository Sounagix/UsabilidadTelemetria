#pragma once
#include "IPersistence.h"
#include "EventInfo.h"
#include <list>
#include <iostream>
#include <bitset>

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
	static std::bitset<(uint64_t)EventInfo::EventType::NUM_EVENTS> _bitMaskEvents;

	Tracker();

	static void DefaultBitMask();

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
	static TrackerEvent* CreateNewEvent(long long timeStamp, std::string idUser, std::string idGame, int eType);
	/// <summary>
	/// Limpia la basura del tracker
	/// </summary>
	static void Free();
	/// <summary>
	/// Devuelve la instancia del tracker
	/// </summary>
	static Tracker* GetInstance();
	/// <summary>
	/// Devuelve el timeStamp actual
	/// </summary>
	static long long GetTimeStamp();
	/// <summary>
	/// Asigna una nueva máscara de bits para los eventos
	/// </summary>
	/// <param name="bits">Máscara de bits recibida</param>
	/// <param name="flip">Determina si se invierte el orden de la máscara de bits</param>
	static void SetBitMaskEvents(const std::string bits, bool flip = true);
};