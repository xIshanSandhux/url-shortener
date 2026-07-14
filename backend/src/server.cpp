#include "server.h"
#include <boost/beast.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/json/value.hpp>
#include <boost/system/detail/error_code.hpp>
using namespace std;

// server constructor
HttpServer::HttpServer(int port,
        boost::asio::io_context& io_context
    ):
    port_(port),
    io_context_(io_context),
    accept_(io_context_, tcp::endpoint(tcp::v4(),port_))
    {

        run_server();
    }

// starting a new connection + accepting client connections
void HttpServer::run_server(){
    TcpConnection::pointer new_connection = TcpConnection::create(io_context_);

    // lamdba function which uses "this" because there will always be 1 instance
    // of the HttpServer object and it will never get destroyed 
    // so the complier knows which HttpServer obj to use.
    accept_.async_accept(
            new_connection->socket(),
            [this,new_connection] (const boost::system::error_code& error){
                handle_accept(new_connection, error);
            }
            );
}

// handling incoming client requests
void HttpServer::handle_accept(TcpConnection::pointer new_connection,const boost::system::error_code& error){
    // if no error then process the request
    if(!error){
        new_connection->process();
    }

    // to start accepting new connections
    run_server();

}
