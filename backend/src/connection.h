#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include <boost/asio.hpp>
#include <memory>
using boost::asio::ip::tcp;
using namespace std;
class TcpConnection:
    public std::enable_shared_from_this<TcpConnection>
{
public:
    typedef std::shared_ptr<TcpConnection> pointer;
    static pointer create(boost::asio::io_context& io_context);
    tcp::socket& socket();
    void process();

private:
    TcpConnection(boost::asio::io_context& io_context):socket_(io_context){}
    tcp::socket socket_;
    void handle_write();
};
#endif  
