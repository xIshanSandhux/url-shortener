#include "connection.h"
#include <boost/asio/impl/write.hpp>

// constructor to create new connection
TcpConnection::pointer TcpConnection::create(boost::asio::io_context &io_context){
    return pointer(new TcpConnection(io_context));
}

// getter for returning connection socket
tcp::socket& TcpConnection::socket(){
    return socket_;
}

// processing the request
void TcpConnection::process(){
    boost::asio::async_write(socket_,boost::asio::buffer("sample response"),bind(&TcpConnection::handle_write, shared_from_this()));
}

// callback for handling the writes
void TcpConnection::handle_write(){
    cout<<"HANDLE WRITE CALLBACK CALLED"<<endl;
}
