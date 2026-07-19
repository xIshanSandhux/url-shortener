#include "http_request_parser.h"
#include <boost/asio/read_until.hpp>
#include <istream>
// void processRequest(boost::asio::streambuf& buf, HttpRequest& req){
//
// }

HttpRequest parseRequest(boost::asio::ip::tcp::socket& socket){
    HttpRequest finalreq;
    boost::asio::streambuf buf;
    //reading from the socket and then adding to the buffer
    boost::asio::read_until(socket,buf,"\r\n\r\n");

    std::istream buffer(&buf);
    // try{
    //     // reading the stream from socket until the end of headers
    //     // boost::asio::async_read_until(socket,buf,"\r\n\r\n",
    //     //         [&buf,&finalreq](boost::system::error_code& ec, std::size_t bt){
    //     //         processRequest(buf,finalreq);
    //     //         });
    // }
    // catch{
    //     return;
    // }
}

