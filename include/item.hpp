#pragma once
#include <string>

class Item {
public:
    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;
    std::string location;

    Item(int id,
        const std::string& name,
        const std::string& category,
        double price,
        int quantity,
        const std::string& location);
};