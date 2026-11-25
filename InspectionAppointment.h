#ifndef VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H
#define VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H

#include <cstdint>
#include "Car.h"
#include <string>

enum class AppointmentStatus {booked, accepted, cancelled, processing, completed, document_issued };

class InspectionAppointment {
private:
    uint32_t ID_registration;
    Car vehicle;
    std::string date_time;
    AppointmentStatus appointment_stage;
public:
    InspectionAppointment(uint32_t ID_registration, Car vehicle, std::string date_time);
    bool AcceptVehicle();
    bool CancelAppointment();
};



#endif //VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H
