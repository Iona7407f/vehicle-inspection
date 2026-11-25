#ifndef VEHICLE_IMSPECTION_CAR_H
#define VEHICLE_IMSPECTION_CAR_H
#include <string>

class Car
{
private:
    std::string mark;
    std::string model;
    std::string gov_number;
public:
     Car(std::string mark, std::string model, std::string gov_number);
};

#endif //VEHICLE_IMSPECTION_CAR_H
