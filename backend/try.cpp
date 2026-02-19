#include <iostream>
#include <sqlite3.h>
using namespace std;

int main(){
    sqlite3* db;
    int open = sqlite3_open("test.db",&db);
    cout<<open<<endl;
    if (open){
        cout<<"hello"<<endl;
    }

    if(sqlite3_open("test1.db",&db)){
        cout<<"db opened"<<endl;
    }
    cout<<sqlite3_open("test1.db",&db)<<endl;
    cout<<"db opened properly?"<<endl;
    return 0;
}
