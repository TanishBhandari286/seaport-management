#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Passenger class definition
class Passenger {
private:
    int id;
    string name;
    int age;
    string nationality;
    int shipId;

public:
    Passenger(int id, string name, int age, string nationality) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->nationality = nationality;
        this->shipId = -1;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getNationality() {
        return nationality;
    }

    int getShipId() {
        return shipId;
    }

    void setShipId(int newShipId) {
        shipId = newShipId;
    }
};

// Ship class definition
class Ship {
private:
    int id;
    string name;
    string destination;
    int capacity;
    int currentOccupancy;
    vector<Passenger*> passengers;
    int harborId;

public:
    Ship(int id, string name, string destination, int capacity) {
        this->id = id;
        this->name = name;
        this->destination = destination;
        this->capacity = capacity;
        this->currentOccupancy = 0;
        this->harborId = -1;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getDestination() {
        return destination;
    }

    int getCapacity() {
        return capacity;
    }

    int getCurrentOccupancy() {
        return currentOccupancy;
    }

    vector<Passenger*> getPassengersOnBoard() {
        return passengers;
    }

    int getHarborId() {
        return harborId;
    }

    bool isFull() {
        return currentOccupancy >= capacity;
    }

    bool isEmpty() {
        return currentOccupancy == 0;
    }

    bool embarkPassenger(Passenger* passenger) {
        if (isFull()) {
            return false;
        }
        passengers.push_back(passenger);
        currentOccupancy++;
        passenger->setShipId(id);
        return true;
    }

    bool disembarkPassenger(Passenger* passenger) {
        vector<Passenger*>::iterator it = find(passengers.begin(), passengers.end(), passenger);
        if (it != passengers.end()) {
            passengers.erase(it);
            currentOccupancy--;
            passenger->setShipId(-1);
            return true;
        }
        return false;
    }

    void setHarborId(int newHarborId) {
        harborId = newHarborId;
    }
};

// Harbor class definition
class Harbor {
private:
    int id;
    string name;
    string location;
    int maxCapacity;
    int currentOccupancy;
    vector<Ship*> dockedShips;

public:
    Harbor(int id, string name, string location, int maxCapacity) {
        this->id = id;
        this->name = name;
        this->location = location;
        this->maxCapacity = maxCapacity;
        this->currentOccupancy = 0;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getLocation() {
        return location;
    }

    int getMaxCapacity() {
        return maxCapacity;
    }

    int getCurrentOccupancy() {
        return currentOccupancy;
    }

    vector<Ship*> getDockedShips() {
        return dockedShips;
    }

    bool isFull() {
        return currentOccupancy >= maxCapacity;
    }

    bool isEmpty() {
        return currentOccupancy == 0;
    }

    bool dockShip(Ship* ship) {
        if (isFull()) {
            return false;
        }
        dockedShips.push_back(ship);
        currentOccupancy++;
        return true;
    }

    bool undockShip(Ship* ship) {
        vector<Ship*>::iterator it = find(dockedShips.begin(), dockedShips.end(), ship);
        if (it != dockedShips.end()) {
            dockedShips.erase(it);
            currentOccupancy--;
            return true;
        }
        return false;
    }
};

// SeaportManagementSystem class definition
class SeaportManagementSystem {
private:
    vector<Harbor*> harbors;
    vector<Ship*> ships;
    vector<Passenger*> passengers;

public:
    SeaportManagementSystem() {
    }

    ~SeaportManagementSystem() {
        for (Harbor* harbor : harbors) {
            delete harbor;
        }
        for (Ship* ship : ships) {
            delete ship;
        }
        for (Passenger* passenger : passengers) {
            delete passenger;
        }
    }

    bool addHarbor(Harbor* harbor) {
        for (Harbor* h : harbors) {
            if (h->getId() == harbor->getId()) {
                return false;
            }
        }
        harbors.push_back(harbor);
        return true;
    }

    bool removeHarbor(int harborId) {
        vector<Harbor*>::iterator it = find_if(harbors.begin(), harbors.end(),
            [harborId](Harbor* h) { return h->getId() == harborId; });
        
        if (it != harbors.end()) {
            delete *it;
            harbors.erase(it);
            return true;
        }
        return false;
    }

    bool addShip(Ship* ship) {
        for (Ship* s : ships) {
            if (s->getId() == ship->getId()) {
                return false;
            }
        }
        ships.push_back(ship);
        return true;
    }

    bool removeShip(int shipId) {
        vector<Ship*>::iterator it = find_if(ships.begin(), ships.end(),
            [shipId](Ship* s) { return s->getId() == shipId; });
        
        if (it != ships.end()) {
            delete *it;
            ships.erase(it);
            return true;
        }
        return false;
    }

    bool addPassenger(Passenger* passenger) {
        for (Passenger* p : passengers) {
            if (p->getId() == passenger->getId()) {
                return false;
            }
        }
        passengers.push_back(passenger);
        return true;
    }

    bool removePassenger(int passengerId) {
        vector<Passenger*>::iterator it = find_if(passengers.begin(), passengers.end(),
            [passengerId](Passenger* p) { return p->getId() == passengerId; });
        
        if (it != passengers.end()) {
            delete *it;
            passengers.erase(it);
            return true;
        }
        return false;
    }

    Harbor* findAvailableHarborForShip(int shipId) {
        Ship* ship = nullptr;
        for (Ship* s : ships) {
            if (s->getId() == shipId) {
                ship = s;
                break;
            }
        }
        
        if (!ship) {
            return nullptr;
        }
        
        for (Harbor* harbor : harbors) {
            if (!harbor->isFull()) {
                return harbor;
            }
        }
        
        return nullptr;
    }

    vector<Ship*> findShipsAtHarbor(int harborId) {
        vector<Ship*> result;
        for (Ship* ship : ships) {
            if (ship->getHarborId() == harborId) {
                result.push_back(ship);
            }
        }
        return result;
    }

    vector<Ship*> findShipsByDestination(string destination) {
        vector<Ship*> result;
        for (Ship* ship : ships) {
            if (ship->getDestination() == destination) {
                result.push_back(ship);
            }
        }
        return result;
    }

    vector<Passenger*> findPassengersByShip(int shipId) {
        vector<Passenger*> result;
        for (Passenger* passenger : passengers) {
            if (passenger->getShipId() == shipId) {
                result.push_back(passenger);
            }
        }
        return result;
    }

    vector<Harbor*> getHarbors() {
        return harbors;
    }

    vector<Ship*> getShips() {
        return ships;
    }

    vector<Passenger*> getPassengers() {
        return passengers;
    }
}; 