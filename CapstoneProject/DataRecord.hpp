#pragma once
#include <string>

struct DataRecord {
    std::string id;
    std::string name;
    int age;
    double value;
    std::string category;    

    // Default constructor with initialization
    DataRecord() : age(0), value(0.0) {}
};