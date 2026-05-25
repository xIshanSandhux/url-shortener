#include "server.h"
#include <boost/beast.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/json/value.hpp>
#include <boost/system/detail/error_code.hpp>
using namespace std;

// server constructor
HttpServer::HttpServer(int port,Database &db,
        boost::asio::io_context& io_context
    ):
    port_(port),
    db_(db),
    io_context_(io_context),
    accept_(io_context_, tcp::endpoint(tcp::v4(),port_))
    {

        run_server();
    }

// starting a new connection + accepting client connections
void HttpServer::run_server(){
    TcpConnection::pointer new_connection = TcpConnection::create(io_context_);

    accept_.async_accept(
            new_connection->socket(),
            bind(&HttpServer::handle_accept, this, new_connection, boost::asio::placeholders::error)
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
