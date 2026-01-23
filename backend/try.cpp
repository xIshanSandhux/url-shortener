#include <boost/json/src.hpp>
#include <iostream>
namespace json = boost::json;
using namespace std;

int main(){

    json::object j;

    j["h"] = 12;

    // cout<<"hello"<<endl;
    cout<<j<<endl;
    // cout<<"hello"<<endl;

    return 0;
}
