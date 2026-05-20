#include "server.h"
#include <boost/beast.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/json/value.hpp>
using namespace std;

HttpServer::HttpServer(int port,Database &db,
        boost::asio::io_context& io_context
    ):
    port_(port),
    db_(db),
    io_context_(io_context),
    accept_(io_context_, tcp::endpoint(tcp::v4(),port_))
    {

        run_server();
    }

void HttpServer::run_server(){
}
