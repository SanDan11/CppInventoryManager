#include "database_manager.hpp"

bool DatabaseManager::open(const std::string &dbPath)
{
    int result = sqlite3_open(dbPath.c_str(), &db);
    if (result != SQLITE_OK)
    {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::cout << "Database connected: " << dbPath << std::endl;
    return true;
}

bool DatabaseManager::createTables()
{
    std::string sql = R"(
CREATE TABLE IF NOT EXISTS items (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    brand TEXT NOT NULL,
    price REAL NOT NULL,
    quantity INTEGER NOT NULL,
    location TEXT NOT NULL
);

    )";
    return execute(sql);
}

bool DatabaseManager::insertItem(const Item &item)
{
    const char *sql = "INSERT INTO items (name, brand, price, quantity, location) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare INSERT: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, item.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, item.getBrand().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, item.getPrice());
    sqlite3_bind_int(stmt, 4, item.getQuantity());
    sqlite3_bind_text(stmt, 5, item.getLocation().c_str(), -1, SQLITE_STATIC);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);

    if (!success)
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    else
        std::cout << "Item inserted: " << item.getName() << std::endl;

    return success;
}

std::vector<Item> DatabaseManager::getAllItems()
{
    std::vector<Item> items;
    const char *sql = "SELECT id, name, brand, price, quantity, location FROM items;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare SELECT: " << sqlite3_errmsg(db) << std::endl;
        return items;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        std::string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string brand = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        double price = sqlite3_column_double(stmt, 3);
        int quantity = sqlite3_column_int(stmt, 4);
        std::string location = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));

        items.emplace_back(id, name, brand, price, quantity, location);
    }

    sqlite3_finalize(stmt);
    return items;
}

bool DatabaseManager::updateItemQuantity(int id, int newQuantity)
{
    const char *sql = "UPDATE items SET quantity = ? WHERE id = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare UPDATE: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, newQuantity);
    sqlite3_bind_int(stmt, 2, id);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return success;
}

bool DatabaseManager::deleteItem(int id)
{
    const char *sql = "DELETE FROM items WHERE id = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Failed to prepare DELETE: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, id);
    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return success;
}

bool DatabaseManager::execute(const std::string &sql)
{
    char *errMsg = nullptr;
    int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
void DatabaseManager::close()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "Database closed" << std::endl;
    }
}