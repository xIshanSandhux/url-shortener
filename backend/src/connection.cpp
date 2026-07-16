#include "connection.h"
#include <boost/asio/impl/write.hpp>
#include <boost/system/detail/error_code.hpp>

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
std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 16\r\n"
        "\r\n"
        "sample response\n";
cout<<"ENETERED THE PROCESS FUNCTION"<<endl;
    // gives the OS what to send as a response and because this is async need a callback
    // to make sure everything was sent as expected without errors
    // the callback gets triggered once the io detects that the message was sent
    // as expected or got an error back
    boost::asio::async_write(socket_,boost::asio::buffer(response),
            [self=shared_from_this()] (const boost::system::error_code& ec, std::size_t bt){
            self->handle_write(ec,bt);
            }
        );
}

// callback for handling the writes
void TcpConnection::handle_write(const boost::system::error_code& ec, std::size_t bt){
    if (ec){
        cout<<"ERROR OCCURED WHILE WRITING BACK TO THE CLIENT"<<endl;
        return;
    }
    cout<<"SUCCESSFULLY COMPLETED THE REQUEST. WRITTEN: "<<bt<<" BYTES" <<endl;
}
