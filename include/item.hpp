#pragma once
#include <string>
#include <iostream>

class Item {
private:
    int id;
    std::string name;
    std::string brand;
    double price;
    int quantity;
    std::string location;

public:
        Item(int id, const std::string& name, const std::string& brand, double price, int quantity, const std::string& location)
            : id(id), name(name), brand(brand), price(price), quantity(quantity), location(location) {}


    // --- Getters ---
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getBrand() const { return brand; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    std::string getLocation() const { return location; }

    // setters
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
    void setLocation(const std::string& loc) {location = loc; }

    void print() const {
        std::cout << id << " | " << name << " | " << brand << " | "
                  << price <<  " | " << quantity << " | " << location << std::endl;
    }

};