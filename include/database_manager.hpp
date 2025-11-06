#pragma once
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <vector>

#include <item.hpp>
#include <sqlite3.h>


class DatabaseManager {
private:
    sqlite3* db = nullptr;

public:
    bool open(const std::string& dbPath);

    bool createTables();

    void close();

    bool execute(const std::string& sql);

    // CRUD
    bool insertItem(const Item& item);

    std::vector<Item> getAllItems();

    bool updateItemQuantity(int id, int newQuantit);

    bool deleteItem(int id);

};