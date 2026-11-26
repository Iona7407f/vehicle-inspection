#include "InspectionItem.h"

InspectionItem::InspectionItem(std::string item_name)
    :item_name(item_name) {}

void InspectionItem::RecordResult(bool passed)
{
    if (passed == true)
    {
        tech_inspection_status = TechInspectionStatus::passed;
    }else
    {
        tech_inspection_status = TechInspectionStatus::failed;
    }
}

std::string InspectionItem::GetItemName() const
{
    return item_name;
}

TechInspectionStatus InspectionItem::GetStatus() const
{
    return tech_inspection_status;
}