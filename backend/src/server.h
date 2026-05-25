#ifndef SERVER_HPP
#define SERVER_HPP
#include "connection.h"
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;
class Database;

class HttpServer{
    private:
        Database &db_;
        int port_;
        // reference to io_context
        boost::asio::io_context& io_context_;
        tcp::acceptor accept_;
        void run_server();
        void handle_accept(TcpConnection::pointer new_connection,const boost::system::error_code& error);

    public:
        HttpServer(int port, Database& db, boost::asio::io_context& io_context);
};

#endif 
