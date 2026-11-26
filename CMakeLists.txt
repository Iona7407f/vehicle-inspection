cmake_minimum_required(VERSION 4.2)
project(Vehicle_imspection)

set(CMAKE_CXX_STANDARD 20)

add_executable(Vehicle_imspection main.cpp
        InspectionAppointment.h
        Car.h
        Car.cpp
        InspectionAppointment.cpp
        InspectionItem.cpp
        InspectionItem.h)
