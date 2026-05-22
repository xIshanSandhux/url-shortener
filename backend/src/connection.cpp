#include "connection.h"
#include <boost/asio/impl/write.hpp>

TcpConnection::pointer TcpConnection::create(boost::asio::io_context &io_context){
    return pointer(new TcpConnection(io_context));
}

tcp::socket& TcpConnection::socket(){
    return socket_;
}

void TcpConnection::process(){
    boost::asio::async_write(socket_,boost::asio::buffer("sample response"),bind(&TcpConnection::handle_write, shared_from_this()));
}

// callback for handling the writes
void TcpConnection::handle_write(){}
