#include "connection.h"

TcpConnection::pointer TcpConnection::create(boost::asio::io_context &io_context){
    return pointer(new TcpConnection(io_context));
}

tcp::socket& TcpConnection::socket(){
    return socket_;
}
