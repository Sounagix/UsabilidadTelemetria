#pragma once
#include "IPersistence.h"
#include <queue>

class TrackerEvent;
class ISerializer;

class FilePersistence : public IPersistence
{
private:
	std::queue<TrackerEvent*> _eventQueue;
	ISerializer* _serializer = nullptr;

public:
	FilePersistence() {};
	/// <summary>
	/// Inicializa el metodo de persistencia
	/// </summary>
	virtual bool init(TypeOfFile type);
	/// <summary>
	/// Realiza el volcado del evento
	/// </summary>
	/// <param name="trackEvent"></param>
	virtual void send(TrackerEvent* trackEvent);
	/// <summary>
	/// Vuelca los datos de la cola en el archivo
	/// correspondiente
	/// </summary>
	virtual void flush();
};

