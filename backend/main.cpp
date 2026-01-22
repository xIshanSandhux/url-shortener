#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
// #include <boost/json.hpp>
// #include <boost/json/object.hpp>
// #include <boost/json/serialize.hpp>

#include <iostream>
using namespace std;
namespace beast = boost::beast;
namespace http = beast::http;
using boost::asio::ip::tcp;

//creating sample request handler
void handle_request(http::request<http::string_body> req, 
        http::response<http::string_body> &res
        ){
    cout<<"Method: "<<req.method()<<endl;
    cout<<"Target: "<<req.target()<<endl;
    cout<<"Body: "<<req.body()<<endl;

    if(req.method()==http::verb::get && req.target()=="/health"){
        res.body() = "server is running";
        cout<<res.body()<<endl;
    }

    res.result(http::status::ok);
    res.set(http::field::content_type,"text/html");
    res.prepare_payload();
}

void run_server(){

    // using epoll under the hood for event loops and stuff
    boost::asio::io_context io_context;
    // creating a v4 endpoint with port 8080 for the main server
    tcp::endpoint endpoint(tcp::v4(),8080);
    // listening socket (accepting connections)
    tcp::acceptor acceptor(io_context, endpoint);
    
    cout<<"Server Started. Waiting for Connections.."<<endl;

    for(;;){
        // creating an empty socket object
        cout<<"waiting for a client to join"<<endl;
        tcp::socket sock(io_context);
        // accepting the connection (tcp 3way handshake) and adding that to the empty socket
        acceptor.accept(sock);
        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(sock,buffer,req);
        http::response<http::string_body> res;
        // handle_request(req, res);
        handle_request(req,res);
        cout<<res<<endl;
        http::write(sock,res);
        cout<<"connected successfully"<<endl;
        cout<<"connection closed"<<endl;
    }
}

int main(){
    run_server();
    return 0;
}
