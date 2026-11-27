#ifndef VEHICLE_IMSPECTION_INSPECTIONSYSTEM_H
#define VEHICLE_IMSPECTION_INSPECTIONSYSTEM_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "InspectionAppointment.h"

class InspectionSystem
{
private:
    std::vector <InspectionAppointment> appointments;
    std::uint32_t next_id = 1;
public:
    std::uint32_t CreateAppointment(const Car &car, std::string date_time);
    InspectionAppointment* FindAppointment(std::uint32_t id);
    void PrintAppointments() const;
};


#endif //VEHICLE_IMSPECTION_INSPECTIONSYSTEM_H
