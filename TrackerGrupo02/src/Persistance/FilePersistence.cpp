#include "FilePersistence.h"
#include "JsonSerializer.h"
#include "AllEvents.h"
#include <iostream>

bool FilePersistence::init(TypeOfFile type)
{
	switch (type)
	{
	case TypeOfFile::Json:
		_serializer = new JsonSerializer();
		break;
	case TypeOfFile::Csv:
		std::cout << "Sigan viendo...\n";
		break;
	default:
		std::cout << "Formato no reconocido...\n";
		return false;
		break;
	}

	return true;
}

void FilePersistence::send(TrackerEvent* trackEvent)
{
	_eventQueue.push(trackEvent);
}

void FilePersistence::flush()
{
	// TODO: Decirle al Serialize que serialice los datos del TrackerEvent
	// para posteriormente recogerlos y crear el archivo Json
	while (!_eventQueue.empty())
	{
		TrackerEvent* e = _eventQueue.front();
		std::string json = _serializer->serialize(e);
		// TODO: Parsear al archivo de texto
		std::cout << json << "- Success...\n";
		_eventQueue.pop();
		delete e;
		e = nullptr;
	}
}
