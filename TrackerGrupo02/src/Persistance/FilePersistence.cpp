#include "FilePersistence.h"
#include "JsonSerializer.h"
#include "AllEvents.h"
#include <iostream>
#include <filesystem>
#include <iterator>

bool FilePersistence::initEventCount()
{
	// ¿La ruta es correcta?
	if (!std::filesystem::exists(_pathFile))
	{
		std::cout << "La ruta especificada no es correcta: " << _pathFile << std::endl;
		return false;
	}

	// ¿Cuantos archivos de los eventos existen?
	int numEvents = (int)EventInfo::EventType::NUM_EVENTS;
	int i = 0;
	while (i < numEvents)
	{
		std::string dir = _pathFile + EventInfo::eventName[i];
		if (std::filesystem::exists(dir))
		{
			auto var1 = std::filesystem::directory_iterator(dir);
			auto var2 = std::filesystem::directory_iterator{};
			// Si no existe, se añade
			long long count = std::distance(var1, var2);
			_eventCount[(EventInfo::EventType)i] = count;
		}

		i++;
	}

	return true;
}

FilePersistence::FilePersistence(std::string pathFile) : _pathFile(pathFile)
{
	_pathFile = pathFile;
	if (_pathFile[_pathFile.length() - 1] != '\\' && _pathFile[_pathFile.length() - 1] != '/') 
	{
		_pathFile += '/';
	}
}

FilePersistence::~FilePersistence()
{

	while (!_eventQueue.empty()) {
		auto e = _eventQueue.front();
		_eventQueue.pop();

		delete e;
		e = nullptr;
	}

	if (_serializer != nullptr)
	{
		delete _serializer;
		_serializer = nullptr;
	}
}

bool FilePersistence::init(TypeOfFile type)
{
	switch (type)
	{
	case TypeOfFile::Json:
		_serializer = new JsonSerializer();
		break;
	case TypeOfFile::Csv:
		std::cout << "CSV no sportado. WIP\n";
		return false;
		break;
	default:
		std::cout << "Formato no reconocido...\n";
		return false;
		break;
	}

	return initEventCount();
}

void FilePersistence::send(TrackerEvent* trackEvent)
{
	_eventQueue.push(trackEvent);
}

void FilePersistence::flush()
{
	// Limpieza de la cola
	while (!_eventQueue.empty())
	{
		TrackerEvent* e = _eventQueue.front();
		EventInfo::EventType eType = e->getEventType();
		std::string json = _serializer->serialize(e);
		// 1. ¿Existe la carpeta destino?
		std::string dirPath = _pathFile + EventInfo::eventName[(int)eType];
		if (!std::filesystem::exists(dirPath))
		{
			//Si no existe creamos el directorio
			std::filesystem::create_directory(dirPath);
		}

		//2. ¿El diccionario contiene info del evento?
		long long fileCount = 0;
		if (_eventCount.count(eType) == 0)
		{
			// Si no existe, se añade
			_eventCount[eType] = 0;
		}
		else
		{
			// Si existe, aumenta el conteo
			_eventCount.at(eType)++;
			fileCount = _eventCount.at(eType);
		}
		// 3. Asignacion del nombre
		std::string aux = dirPath + "/" + EventInfo::eventName[(int)eType] + std::to_string(fileCount);

		// 4. Volcado de los datos
		std::ofstream file(aux + ".json");
		file << json;
		file.close();

		// 5. Limpieza 
		_eventQueue.pop();
		delete e;
		e = nullptr;
	}
}
