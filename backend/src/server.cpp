#include "server.h"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/json/value.hpp>
#include <iostream>
#include "db.h"
using namespace std;
namespace beast = boost::beast;
namespace http = beast::http;
using boost::asio::ip::tcp;


HttpServer::HttpServer(int port, Database &db):port_(port),db_(db){}

void HttpServer::run_server(){

    // using epoll under the hood for event loops and stuff
    boost::asio::io_context io_context;
    // creating a v4 endpoint with port 8080 for the main server
    tcp::endpoint endpoint(tcp::v4(),port_);
    // listening socket (accepting connections)
    tcp::acceptor acceptor(io_context, endpoint);
    
    cout<<"Server Started at port: "<<port_<<endl;

    for(;;){
        // creating an empty socket object
        tcp::socket sock(io_context);
        // accepting the connection (tcp 3way handshake) and adding that to the empty socket
        acceptor.accept(sock);
        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(sock,buffer,req);
        http::response<http::string_body> res;
        // handle_request(req,res);
        cout<<res<<endl;
        http::write(sock,res);
        cout<<"connected successfully"<<endl;
        cout<<"connection closed"<<endl;
    }
}
