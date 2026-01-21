#include <boost/asio.hpp>
#include <iostream>
using namespace std;
using boost::asio::ip::tcp;

int main(){

    // using epoll under the hood for event loops and stuff
    boost::asio::io_context io_context;
    // creating a v4 endpoint with port 8080 for the main server
    tcp::endpoint endpoint(tcp::v4(),8080);
    // listening socket (accepting connections)
    tcp::acceptor acceptor(io_context, endpoint);

    for(;;){
        // creating an empty socket object
        tcp::socket sock(io_context);
        // accepting the connection (tcp 3way handshake) and adding that to the empty socket
        acceptor.accept(sock);
        cout<<"connected successfully"<<endl;
        cout<<"connection closed"<<endl;
    }
    return 0;
}
