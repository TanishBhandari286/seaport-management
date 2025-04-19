#include "seaport_classes.cpp"

int main() {
    SeaportManagementSystem* system = new SeaportManagementSystem();
    
    Harbor* harbor1 = new Harbor(1, "New York Harbor", "New York", 5);
    Harbor* harbor2 = new Harbor(2, "Los Angeles Harbor", "Los Angeles", 3);
    
    system->addHarbor(harbor1);
    system->addHarbor(harbor2);
    
    Ship* ship1 = new Ship(1, "Queen Mary", "London", 1000);
    Ship* ship2 = new Ship(2, "Titanic", "Southampton", 2000);
    
    system->addShip(ship1);
    system->addShip(ship2);
    
    Passenger* passenger1 = new Passenger(1, "John Doe", 30, "American");
    Passenger* passenger2 = new Passenger(2, "Jane Smith", 25, "British");
    
    system->addPassenger(passenger1);
    system->addPassenger(passenger2);
    
    harbor1->dockShip(ship1);
    ship1->setHarborId(harbor1->getId());
    
    harbor2->dockShip(ship2);
    ship2->setHarborId(harbor2->getId());
    
    ship1->embarkPassenger(passenger1);
    ship2->embarkPassenger(passenger2);
    
    cout << "Ships at New York Harbor:" << endl;
    vector<Ship*> shipsAtHarbor = system->findShipsAtHarbor(harbor1->getId());
    for (Ship* ship : shipsAtHarbor) {
        cout << "- " << ship->getName() << endl;
    }
    
    cout << "\nPassengers on Queen Mary:" << endl;
    vector<Passenger*> passengersOnShip = system->findPassengersByShip(ship1->getId());
    for (Passenger* passenger : passengersOnShip) {
        cout << "- " << passenger->getName() << " (" << passenger->getNationality() << ")" << endl;
    }
    
    delete system;
    
    return 0;
} 