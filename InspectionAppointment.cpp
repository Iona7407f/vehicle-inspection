#include "InspectionAppointment.h"

InspectionAppointment::InspectionAppointment(uint32_t ID_registration, Car vehicle, std::string date_time)
    :ID_registration(ID_registration),vehicle(vehicle),date_time(date_time), appointment_stage(AppointmentStatus::booked) {}

bool InspectionAppointment::AcceptVehicle()
{
    if (appointment_stage == AppointmentStatus::booked)
    {
        appointment_stage = AppointmentStatus::accepted;
        return true;
    } else
    {
        return false;
    }
}

bool InspectionAppointment::CancelAppointment()
{
    if (appointment_stage == AppointmentStatus::booked)
    {
        appointment_stage = AppointmentStatus::cancelled;
        return true;
    }else
    {
        return false;
    }
}

