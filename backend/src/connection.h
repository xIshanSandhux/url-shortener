#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include <boost/asio.hpp>
#include <memory>
#include <iostream>
using boost::asio::ip::tcp;
using namespace std;
class TcpConnection:
    public std::enable_shared_from_this<TcpConnection>
{
public:
    // alias for the shared_pointer
    using pointer =std::shared_ptr<TcpConnection>; 
    static pointer create(boost::asio::io_context& io_context);
    tcp::socket& socket();
    void process();

private:
    // constructor to create a new tcp connection + a new socket for every client
    TcpConnection(boost::asio::io_context& io_context):socket_(io_context){}
    tcp::socket socket_;
    void handle_write(const boost::system::error_code& ec, std::size_t bt);
};
#endif  
