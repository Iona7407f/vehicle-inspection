#ifndef VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H
#define VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H
#include "InspectionItem.h"
#include <cstdint>
#include "Car.h"
#include <string>
#include <vector>

enum class AppointmentStatus {booked, accepted, cancelled, processing, completed, document_issued };

class InspectionAppointment {
private:
    uint32_t ID_registration;
    Car vehicle;
    std::string date_time;
    AppointmentStatus appointment_stage;
    std::vector<InspectionItem> inspection_items;
public:
    InspectionAppointment(uint32_t ID_registration, Car vehicle, std::string date_time);
    bool AcceptVehicle();
    bool CancelAppointment();
    bool StartInspection();
    bool RecordItemResult(std::size_t index, bool passed);

};



#endif //VEHICLE_IMSPECTION_INSPECTIONAPPOINTMENT_H
