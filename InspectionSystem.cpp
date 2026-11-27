#include "InspectionSystem.h"
#include "InspectionAppointment.h"

std::uint32_t InspectionSystem::CreateAppointment(const Car &car, std::string date_time)
{
    std::uint32_t current_id = next_id;
    appointments.emplace_back(current_id, car, date_time);
    next_id++;
    return current_id;
}

InspectionAppointment* InspectionSystem::FindAppointment(std::uint32_t id)
{
    for (std::size_t i = 0; i < appointments.size(); ++i)
    {
        if (appointments[i].GetID() ==  id)
        {
            return &appointments[i];
        }
    }
    return nullptr;
}

void InspectionSystem::PrintAppointments() const
{
    if (appointments.empty())
    {
        std::cout << "Appointment is empty" << std::endl;
    }else
    {
        for (std::size_t i = 0; i < appointments.size(); ++i)
        {
            appointments[i].PrintSummary();
        }
    }
}