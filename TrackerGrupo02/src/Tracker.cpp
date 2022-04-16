#include "Tracker.h"
#include "AllEvents.h"
#include "FilePersistence.h"
#include <chrono>

Tracker* Tracker::_instance;
IPersistence* Tracker::_persistenceObject;
std::list<ITrackerAsset> Tracker::_activeTrackers;

Tracker::Tracker() {}

bool Tracker::Init(PersistenceType persistType, TypeOfFile fileType, std::string pathFile)
{
	if (_instance->_persistenceObject != nullptr) {
		std::cout << "El Tracker ya se ha inicializado...\n";
		return false;
	}

	switch (persistType)
	{
	case PersistenceType::FILE:
		_instance->_persistenceObject = new FilePersistence(pathFile);
		break;
	case PersistenceType::SERVER:
		// TODO: Crearlo de forma SERVER
		std::cout << "Server WIP...\n";
		return false;
		break;
	default:
		std::cout << "Formato no reconocido " << (int)persistType << "\n";
		return false;
		break;
	}

	return _instance->_persistenceObject->init(fileType);
}

bool Tracker::End()
{
	// TODO: Comprobacion sobre si el evento esta activado
	// esto solo seria necesario si hacemos trackers 
	// especializados
	try {
		std::cout << "Volcando los datos...\n";
		_instance->_persistenceObject->flush();
	}
	catch (std::exception e) {
		std::cout << "Error al realizar el volcado de los datos:\n" << e.what() << std::endl;
		return false;
	}

	return true;
}

void Tracker::TrackEvent(TrackerEvent* newEvent)
{
	// TODO: Comprobacion sobre si el evento esta activado
	// esto solo seria necesario si hacemos trackers 
	// especializados
	_instance->_persistenceObject->send(newEvent);
}

TrackerEvent* Tracker::CreateNewEvent(long long timeStamp, std::string idUser, std::string idGame, int eType)
{
	TrackerEvent* newEvent;

	switch (eType)
	{
	case (int)EventInfo::EventType::Login:
		newEvent = new Login();
		break;
	case (int)EventInfo::EventType::Logout:
		newEvent = new Logout();
		break;
	case (int)EventInfo::EventType::LoginZone:
		newEvent = new LoginZone();
		break;
	case (int)EventInfo::EventType::LogoutZone:
		newEvent = new LogoutZone();
		break;
	case (int)EventInfo::EventType::OpenInv:
		newEvent = new OpenInv();
		break;
	case (int)EventInfo::EventType::OpenSkills:
		newEvent = new OpenSkills();
		break;
	case (int)EventInfo::EventType::OpenChest:
		newEvent = new OpenChest();
		break;
	case (int)EventInfo::EventType::OpenShop:
		newEvent = new OpenShop();
		break;
	case (int)EventInfo::EventType::UseSkill:
		newEvent = new UseSkill();
		break;
	case (int)EventInfo::EventType::UsePot:
		newEvent = new UsePot();
		break;
	case (int)EventInfo::EventType::TutoTask:
		newEvent = new TutoTask();
		break;
	default:
		std::cout << "Error al generar evento\n";
		return nullptr;
		break;
	}

	newEvent->setEv((EventInfo::EventType)eType);
	newEvent->setTimestamp(timeStamp);
	newEvent->setIdUser(idUser);
	newEvent->setIdGame(idGame);

	return newEvent;
}

Tracker* Tracker::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new Tracker();
	}

	return _instance;
}

void Tracker::Free() 
{
	if (_instance->_persistenceObject) {
		delete _instance->_persistenceObject;
	}
	delete _instance;
}

long long Tracker::GetTimeStamp()
{
	return std::chrono::duration_cast<std::chrono::seconds>(
		std::chrono::system_clock::now().time_since_epoch()).count();;
}
