#include "Car.h"

Car::Car(std::string mark, std::string model, std::string gov_number)
    : mark(mark), model(model), gov_number(gov_number) {}

std::string Car::GetMark() const {
    return mark;
}

std::string Car::GetModel() const {
    return model;
}

std::string Car::GetGovNumber() const {
    return gov_number;
}