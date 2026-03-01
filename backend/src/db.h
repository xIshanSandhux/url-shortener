#ifndef DB_HPP
#define DB_HPP 

#include <sqlite3.h>
#include <string>

class Database{
    private:
        sqlite3* db;

    public:
        Database(const std::string& filename);
        ~Database();
        sqlite3* get();
};

#endif
