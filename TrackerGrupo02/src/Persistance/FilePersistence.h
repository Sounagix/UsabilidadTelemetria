#pragma once
#include "IPersistence.h"
#include "EventInfo.h"
#include <queue>
#include <map>

class ISerializer;

class FilePersistence : public IPersistence
{
private:
	/// <summary>
	/// Cola de eventos
	/// </summary>
	std::queue<TrackerEvent*> _eventQueue;
	/// <summary>
	/// Referencia al serializador
	/// </summary>
	ISerializer* _serializer = nullptr;
	/// <summary>
	/// Ruta de guardado de los archivos
	/// </summary>
	std::string _pathFile = "";
	/// <summary>
	/// Diccionario que contiene el numero de eventos
	/// creados en el directorio destino para cada evento
	/// </summary>
	std::map<EventInfo::EventType, long long> _eventCount;
	/// <summary>
	/// Inicialk
	/// </summary>
	/// <returns></returns>
	bool initEventCount();

public:
	FilePersistence(std::string pathFile);
	virtual ~FilePersistence();
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
	/// Vuelca los datos de la cola en los archivos
	/// correspondientes mostrando los eventos generados
	/// </summary>
	virtual void flush();
};

