#include <iostream>
#include <string>
#include <stdexcept>
#include "db.h";
using namespace std;

Database::Database(const string& db_name):db(nullptr){

    if(sqlite3_open(db_name.c_str(),&db)!=SQLITE_OK){

        throw runtime_error(sqlite3_errmsg(db));
    }
    cout<<"db connection successful"<<endl;
}

sqlite3* Database::get(){
    return db;
}

Database::~Database(){
    sqlite3_close(db);
}
