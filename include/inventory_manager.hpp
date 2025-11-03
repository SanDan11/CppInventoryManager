#pragma once
#include "item.hpp"
#include <vector>
#include <iostream>

class InventoryManager {
private:
    std::vector<Item> items;
public:

void addItem(const Item& item);

void listItems() const;

void removeItem(int id);

void updateQuantity(int id, int newQuantity);

Item* findItemByName(const std::string& name);
};