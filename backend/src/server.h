#ifndef SERVER_HPP
#define SERVER_HPP
#include <boost/asio.hpp>
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

    public:
        HttpServer(int port, Database& db, boost::asio::io_context& io_context);
        // void run_server();
};

#endif 
