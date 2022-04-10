#include "Tracker.h"
#include "TrackerEvent.h"
#include "AllEvents.h"
#include "FilePersistence.h"

Tracker* Tracker::instance;
IPersistence* Tracker::persistenceObject;
std::list<ITrackerAsset> Tracker::activeTrackers;

Tracker::Tracker() {}

bool Tracker::Init(PersistenceType persistType, TypeOfFile fileType)
{
	if (persistenceObject != nullptr) {
		std::cout << "El Tracker ya se ha inicializado...\n";
		return false;
	}

	switch (persistType)
	{
	case PersistenceType::FILE:
		persistenceObject = new FilePersistence();
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

	return persistenceObject->init(fileType);
}

bool Tracker::End(std::string pathFile)
{
	// TODO: Comprobacion sobre si el evento esta activado
	// esto solo seria necesario si hacemos trackers 
	// especializados
	try {
		persistenceObject->flush(pathFile);
	}
	catch (std::exception e) {
		std::cout << "Errorr al realizar el volcado de los datos... " << e.what() << std::endl;
		return false;
	}

	return true;
}

void Tracker::TrackEvent(TrackerEvent* newEvent)
{
	// TODO: Comprobacion sobre si el evento esta activado
	// esto solo seria necesario si hacemos trackers 
	// especializados
	persistenceObject->send(newEvent);
}

TrackerEvent* Tracker::CreateNewEvent(int timeStamp, std::string idUser, std::string idGame, int eType)
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
	if (instance == nullptr) {
		instance = new Tracker();
	}

	return instance;
}
