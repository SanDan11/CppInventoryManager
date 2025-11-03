#include "inventory_manager.hpp"

void InventoryManager::addItem(const Item& item) {
    items.push_back(item);
    std::cout << "✅ Added: " << item.name << " (" << item.category << ")" << std::endl; 
}

void InventoryManager::listItems() const {
    std::cout << "\n Inventory List\n";
    std::cout << "-------------------------------------\n";
    for (const auto& item : items) {
        std::cout << "ID:" << item.id
                  << " | Name: " << item.name
                  << " | Category: " << item.category
                  << " | Price: $" << item.price
                  << " | Qty: " << item.quantity
                  << " | Location: " << item.location << std::endl;
    }
    std::cout << "-------------------------------------\n";
}

void InventoryManager::removeItem(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->id == id) {
            std::cout << "🗑️ Removed: " << it->name << std::endl;
            items.erase(it);
            return;
        }
    }
    std::cout << "⚠️ Item ID " << id << " not found.\n";
}

void InventoryManager::updateQuantity(int id, int newQuantity) {
    for (auto& item : items) {
        if (item.id == id) {
            item.quantity = newQuantity;
            std::cout << "🔁 Updated " << item.name << "new qty: " << newQuantity << std::endl;
        }
    }
    std::cout << " ⚠️ Item ID " << id << " not found.\n";
}

Item* InventoryManager::findItemByName(const std::string& name) {
    for (auto& item : items) {
        if (item.name == name) {
            return &item;
        }
    }
    return nullptr;
}