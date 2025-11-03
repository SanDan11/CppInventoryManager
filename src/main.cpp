#include "inventory_manager.hpp"

int main() {
    std::cout << "🚀 C++ Inventory Manager starting up..." << std::endl;

    InventoryManager manager;

    manager.addItem(Item(1, "Stratocaster", "Guitar", 1299.99, 3, "Warehouse A"));
    manager.addItem(Item(2, "Jazz Bass", "Bass", 1099.50, 4, "Warehouse B"));
    manager.addItem(Item(3, "JCM800", "Amplifier", 2199.00, 2, "Warehouse A"));

    manager.listItems();

    manager.updateQuantity(2, 10);
    manager.removeItem(1);

    Item* found = manager.findItemByName("JCM800");
    if (found) {
        std::cout << "🔍 found: " << found->name << " in " << found->location << std::endl; 
    } else {
        std::cout << "❌ Not found\n";
    }


    return 0;
}
