#pragma once
#include <sqlite3.h>
#include <string>

class DatabaseManager {
private:
    sqlite3* db = nullptr;

public:
    bool open(const std::string& dbPath);

    bool createTables();

    void close();

    bool execute(const std::string& sql);

};