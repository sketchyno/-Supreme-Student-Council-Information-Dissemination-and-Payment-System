#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void drive() = 0; 
};

class Car : public Vehicle {
private:
    int horsepower;
public:
    Car(int horsP) : horsepower(horsP) {}
    void drive() override {
        cout << "Driving car with " << horsepower << " horsepower" << endl;
    }
};

class Truck : public Vehicle {
private:
    int payload_capacity;
public:
    Truck(int capacity) : payload_capacity(capacity) {}
    void drive() override {
        cout << "Driving truck with " << payload_capacity << " tons of payload capacity" <<endl;
    }
};

class Motorcycle : public Vehicle {
private:
    int num_cylinders;
public:
    Motorcycle(int cylinders) : num_cylinders(cylinders) {}
    void drive() override {
        cout << "Driving motorcycle with " << num_cylinders << " cylinders" << endl;
    }
};

class VehicleFleet {
private:
    static const int MAX_VEHICLES = 10;
    Vehicle* vehicles[MAX_VEHICLES];
    int num_vehicles;
public:
    VehicleFleet() : num_vehicles(0) {}
    void addVehicle(Vehicle* vehicle) {
        if (num_vehicles < MAX_VEHICLES) {
            vehicles[num_vehicles++] = vehicle;
        }
    }
    void testDrive() {
        for (int i = 0; i < num_vehicles; i++) {
            vehicles[i]->drive();
        }
    }
};

int main() {
    VehicleFleet fleet;
    Car car(200);
    Truck truck(3);
    Motorcycle motorcycle(2);
    fleet.addVehicle(&car);
    fleet.addVehicle(&truck);
    fleet.addVehicle(&motorcycle);
    fleet.testDrive();
    return 0;
}