// Brian Ozawa Burns 4637799
// This is the only file to submit.

#include <iostream>
#include "car.hpp"
#include <cstddef>
#include <cstring>
using namespace std;

Car::Car(){
    manufacturer = nullptr;
    model = nullptr;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    manufacturer = new char[strlen(manufacturerName) + 1];
    strcpy(manufacturer, manufacturerName);

    model = new char[strlen(modelName) + 1];
    strcpy(model, modelName);

    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
}
Car::Car(Car const& o){
    if (manufacturer){
        delete[] manufacturer;
        manufacturer = nullptr;
    }
    if (model){
        delete[] model;
        model = nullptr;
    }
    manufacturer = new char[strlen(o.getManufacturer()) + 1];
    strcpy(manufacturer, o.getManufacturer());

    model = new char[strlen(o.getModel()) + 1];
    strcpy(model, o.getModel());

    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors().backseatDoors;
    seatCount = o.getSeatCount().seatCount;
}
Car& Car::operator=(Car const& o){
    if (this == &o){
        return *this;
    }
    if (manufacturer){
        delete[] manufacturer;
        manufacturer = nullptr;
    }
    if (model){
        delete[] model;
        model = nullptr;
    }

    manufacturer = new char[strlen(o.getManufacturer()) + 1];
    strcpy(manufacturer, o.getManufacturer());

    model = new char[strlen(o.getModel()) + 1];
    strcpy(model, o.getModel());
    
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors().backseatDoors;
    seatCount = o.getSeatCount().seatCount;

    return *this;
}
Car::~Car(){
    delete[] manufacturer;
    delete[] model;
}
char const* Car::getManufacturer() const{
    return manufacturer;
}
char const* Car::getModel() const{
    return model;
}
PerformanceStats Car::getStats() const{
    PerformanceStats p {horsepower, zeroToSixtyNs, headonDragCoeff};
    return p;
}
uint8_t Car::getSeatCount() const{
    return seatCount;
}
DoorKind Car::getBackseatDoors() const{
    return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer){
    if (manufacturer){
        delete[] manufacturer;
        manufacturer = nullptr;
    }
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
}
void Car::modelNameChange(char const* const newModelName){
    if (model){
        delete[] model;
        model = nullptr;
    }
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
}
void Car::reevaluateStats(PerformanceStats newStats){
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
}
void Car::recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
}
/*
int main(){

    PerformanceStats p {60, 40, 0.8};
    Car tesla("tesla", "Z", p, 6, GullWing);

    cout << tesla.getModel() << endl;

    return 0;
}
*/