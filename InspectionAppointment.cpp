#include "InspectionAppointment.h"
#include "InspectionItem.h"
#include "Car.h"
#include <iostream>

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

bool InspectionAppointment::CompleteInspection()
{
    if (appointment_stage != AppointmentStatus::processing)
    {
        return false;
    }
    bool has_failures = false;
    for (std::size_t i = 0; i < inspection_items.size(); i++)
    {
        if (inspection_items[i].GetStatus() == TechInspectionStatus::unchecked)
        {
            return false;
        }
        if (inspection_items[i].GetStatus() == TechInspectionStatus::failed)
        {
            has_failures = true;
        }
    }
    if (has_failures == true)
    {
        inspection_decision = InspectionDecision::rejected;
    }else
    {
        inspection_decision = InspectionDecision::approved;
    }
    appointment_stage = AppointmentStatus::completed;
    return true;
}

bool InspectionAppointment::IssueDocument()
{
    if (appointment_stage != AppointmentStatus::completed || inspection_decision == InspectionDecision::pending)
    {
        return false;
    }else
    {
        appointment_stage = AppointmentStatus::document_issued;
        return true;
    }
}

void InspectionAppointment::PrintDocument() const
{
    if (appointment_stage == AppointmentStatus::completed || appointment_stage == AppointmentStatus::document_issued)
    {
        std::cout << "--------Inspection Document--------" << std::endl;
        std::cout << "Mark: " << vehicle.GetMark() << std::endl;
        std::cout << "Model: " << vehicle.GetModel() << std::endl;
        std::cout << "Registration number: " << vehicle.GetGovNumber() << std::endl;
        std::cout << "ID: " << ID_registration << std::endl;
        std::cout << "Date: " << date_time << std::endl;
        if (inspection_decision == InspectionDecision::approved) {
            std::cout << "Result: PASSED" << std::endl;
        }else if (inspection_decision == InspectionDecision::rejected) {
            std::cout << "Result: FAILED" << std::endl;
            for (std::size_t i = 0; i < inspection_items.size(); i++) {
                if (inspection_items[i].GetStatus() == TechInspectionStatus::failed) {
                    std::cout <<inspection_items[i].GetItemName() << std::endl;
                }
            }
        }
    }else
    {
        std::cout << "Document is not available" << std::endl;
    }
}

std::uint32_t InspectionAppointment::GetID() const
{
    return ID_registration;
}

void InspectionAppointment::PrintSummary() const
{
    std::cout << "----Summary Information----" << std::endl;
    std::cout << "ID appointment: " << ID_registration << std::endl;
    std::cout << "Registration number: " << vehicle.GetGovNumber() << std::endl;
    std::cout << "Date and time" << date_time << std::endl;
}