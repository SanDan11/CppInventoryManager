#include "database_manager.hpp"


bool DatabaseManager::oen(const sd::string& dbPath) {
    int result = sqlite3_open(dbPath.c_str(), &db);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::cout << "Database connected: " << dbPath << std::endl;
    return true;
}

bool DatabaseManager::createTables() {
    std::string sql = R"(
        CREATE TABLE IF NOT EXISTS items (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            category TEXT NOT NULL,
            price REAL NOT NULL,
            quantity INTEGER NOT NULL,
            location TEXT NOT NULL
        );
    )";
    return execute(sql);
}

bool DatabaseManager::execute(const std::string& sql) {
    char* errMsg = nullptr;
    int result = sqlite3_exec(db, sql.c_str(), nullpt, nullptr, &errMsg);

    
}