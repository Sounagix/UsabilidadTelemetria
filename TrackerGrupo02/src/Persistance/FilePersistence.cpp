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

void FilePersistence::flush(std::string pathFile)
{
	// TODO: Decirle al Serialize que serialice los datos del TrackerEvent
	// para posteriormente recogerlos y crear el archivo Json
	int i = 0;
	while (!_eventQueue.empty())
	{
		TrackerEvent* e = _eventQueue.front();
		std::string json = _serializer->serialize(e);
		// TODO: Parsear al archivo de texto
		
		
		std::string aux = pathFile + e->getEventName() + std::to_string(i);
		if (std::ifstream(aux+".json").good())
		{
			i++;
			aux = pathFile + e->getEventName() + std::to_string(i);
		}
		aux += ".json";
		std::ofstream file(aux);

		file << json ;
		file.close();
		
		_eventQueue.pop();
		delete e;
		e = nullptr;
	}
}
