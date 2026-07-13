#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/beast.hpp>
#include <exception>
#include <iostream>
#include "server.h"
using namespace std;
int main(){
    try{
        boost::asio::io_context io_context;
        // httpserver obj stored on the stack
        HttpServer server(8080,io_context);
        io_context.run();
    }
    catch(exception& e){
        cerr<<"Error while starting up the server: "<<e.what()<<endl;
        return 1;
    }
    return 0;
}
