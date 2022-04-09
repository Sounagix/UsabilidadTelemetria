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

bool Tracker::End()
{
	// TODO: Comprobacion sobre si el evento esta activado
	// esto solo seria necesario si hacemos trackers 
	// especializados
	try {
		persistenceObject->flush();
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
	case (int)EventType::Login:
		newEvent = new Login();
		break;
	case (int)EventType::Logout:
		newEvent = new Logout();
		break;
	case (int)EventType::LoginZone:
		newEvent = new LoginZone();
		break;
	case (int)EventType::LogoutZone:
		newEvent = new LogoutZone();
		break;
	case (int)EventType::OpenInv:
		newEvent = new OpenInv();
		break;
	case (int)EventType::OpenSkills:
		newEvent = new OpenSkills();
		break;
	case (int)EventType::OpenChest:
		newEvent = new OpenChest();
		break;
	case (int)EventType::OpenShop:
		newEvent = new OpenShop();
		break;
	case (int)EventType::UseSkill:
		newEvent = new UseSkill();
		break;
	case (int)EventType::UsePot:
		newEvent = new UsePot();
		break;
	case (int)EventType::TutoTask:
		newEvent = new TutoTask();
		break;
	default:
		std::cout << "Error al generar evento\n";
		return nullptr;
		break;
	}

	newEvent->setEv((EventType)eType);
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
