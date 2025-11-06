#include "inventory_manager.hpp"
#include "database_manager.hpp"

int main() {
    DatabaseManager db;
    db.open("database/inventory.db");
    db.createTables();

    // Create
    Item i1(0, "Stratocaster", "Fender", 1299.99, 5, "Warehouse A");
    db.insertItem(i1);

    // Read
    for (const auto& item : db.getAllItems())
        std::cout << item.getName() << " - " << item.getQuantity() << std::endl;

    // Update
    db.updateItemQuantity(1, 10);

    // Delete
    db.deleteItem(1);

    db.close();
    return 0;
}
