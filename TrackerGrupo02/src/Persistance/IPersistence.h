#pragma once

class TrackerEvent;

enum class TypeOfFile {
	Json = 0,
	Csv = 1,

	NONE = 100
};

class IPersistence
{
public: 
	/// <summary>
	/// Inicializa la persistencia
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	virtual bool init(TypeOfFile type) = 0;
	/// <summary>
	/// Realiza el volcado del evento
	/// </summary>
	/// <param name="trackEvent"></param>
	virtual void send(TrackerEvent* trackEvent) = 0;
	/// <summary>
	/// Vuelca los datos de la cola en el archivo
	/// correspondiente
	/// </summary>
	virtual void flush() = 0;
};