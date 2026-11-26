#ifndef VEHICLE_IMSPECTION_INSPECTIONITEM_H
#define VEHICLE_IMSPECTION_INSPECTIONITEM_H
#include <string>
#include <vector>


enum class TechInspectionStatus {unchecked, passed, failed};

class InspectionItem
{
private:
    std::string item_name;
    TechInspectionStatus tech_inspection_status = TechInspectionStatus::unchecked;
public:
    InspectionItem(std::string item_name);
    void RecordResult(bool passed);
    std::string GetItemName() const;
    TechInspectionStatus GetStatus() const;


};


#endif //VEHICLE_IMSPECTION_INSPECTIONITEM_H
