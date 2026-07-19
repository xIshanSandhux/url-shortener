#include "http_request_parser.h"
#include <boost/asio/impl/read_until.hpp>
#include <boost/asio/streambuf.hpp>

void processRequest(boost::asio::streambuf& buf, HttpRequest& req){

}

HttpRequest parseRequest(boost::asio::ip::tcp& socket){
    HttpRequest finalreq;
    boost::asio::streambuf buf;
    try{
        // reading the stream from socket until the end of headers
        boost::asio::async_read_until(socket,buf,"\r\n\r\n",
                [&buf,&finalreq](boost::system::error_code& ec, std::size_t bt){
                processRequest(buf,finalreq);
                }
    }
}

