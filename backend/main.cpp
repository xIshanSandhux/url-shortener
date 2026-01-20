#include <boost/asio.hpp>
#include <iostream>
using namespace std;
using boost::asio::ip::tcp;

// void hello(){
//     cout<<"hello connected"<<endl;
// }
int main(){

    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(),8080));

    for(;;){
        tcp::socket sock(io_context);
        acceptor.accept(sock);
        cout<<"connected successfully"<<endl;
        // boost::asio::write(socket)
    }
    return 0;
}
