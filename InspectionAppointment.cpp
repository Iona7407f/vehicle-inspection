#include "InspectionAppointment.h"

InspectionAppointment::InspectionAppointment(uint32_t ID_registration, Car vehicle, std::string date_time)
    :ID_registration(ID_registration),vehicle(vehicle),date_time(date_time), appointment_stage(AppointmentStatus::booked)
{
    inspection_items.emplace_back("Brakes");
    inspection_items.emplace_back("Lighting");
    inspection_items.emplace_back("Engine");
    inspection_items.emplace_back("Fuel system");
    inspection_items.emplace_back("Safety equipment");
}

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

bool InspectionAppointment::StartInspection()
{
    if (appointment_stage == AppointmentStatus::accepted)
    {
        appointment_stage = AppointmentStatus::processing;
        return true;
    }else
    {
        return false;
    }
}

bool InspectionAppointment::RecordItemResult(std::size_t index, bool passed)
{
    if (appointment_stage != AppointmentStatus::processing)
    {
        return false;
    }else if (index >= inspection_items.size())
    {
        return false;
    }else
    {
        inspection_items[index].RecordResult(passed);
        return true;
    }
}
