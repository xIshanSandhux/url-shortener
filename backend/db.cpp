#include <iostream>
#include <string>
#include <stdexcept>
#include "db.h"
using namespace std;

Database::Database(const string& db_name):db(nullptr){

    if(sqlite3_open(db_name.c_str(),&db)!=SQLITE_OK){

        throw runtime_error(sqlite3_errmsg(db));
    }
    cout<<"db connection successful"<<endl;


    const char* sql_smt = "CREATE TABLE IF NOT EXISTS urls (id INTEGER PRIMARY KEY AUTOINCREMENT, long_url TEXT NOT NULL);";
    if(sqlite3_exec(db,sql_smt,nullptr,nullptr,nullptr)!=SQLITE_OK){
        cerr<<"Error while executing the SQL query"<<sqlite3_errmsg(db)<<endl;
    }
}

sqlite3* Database::get(){
    return db;
}

Database::~Database(){
    sqlite3_close(db);
}
