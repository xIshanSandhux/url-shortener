#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/beast.hpp>
#include <boost/json/impl/kind.ipp>
#include <boost/json/impl/serialize.ipp>
#include <boost/json/object.hpp>
#include <boost/json/src.hpp>
#include <boost/beast/core/flat_buffer.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>

#include <boost/json/value.hpp>
#include <exception>
#include <iostream>
#include "endpoints.h"
#include "db.h"
#include "server.h"
using namespace std;
namespace beast = boost::beast;
namespace http = beast::http;
namespace json = boost::json;
using boost::asio::ip::tcp;

//creating sample request handler
// void handle_request(http::request<http::string_body> req, 
//         http::response<http::string_body> &res
//         ){
//     json::object json_response;
//     cout<<"Method: "<<req.method()<<endl;
//     cout<<"Target: "<<req.target()<<endl;
//     cout<<"Body: "<<req.body()<<endl;
//     json::value parsed = json::parse(req.body());
//     json::object b = parsed.as_object();
//     string url = b.at("long_url").as_string().c_str();
//
//     //basic health endpoint (will update as the project goes on)
//     if(req.method()==http::verb::get && req.target()=="/health"){
//         json_response["message"] = "Server is Running";
//     }
//     /*
//      * Post request to create the short url
//      * Param: long URL
//      * return: short url || status: 201 
//      */
//     else if(req.method()==http::verb::post && req.target()=="/short-url"){
//         // will be calling the function which will process the long url
//         // and returning the short-url
//         shorten(url);
//     }
//
//     res.body() = json::serialize(json_response);
//     res.result(http::status::ok);
//     res.set(http::field::content_type,"application/json");
//     res.prepare_payload();
// }


int main(){
    try{
        boost::asio::io_context io_context;
        // Database db("urls.db");
        // HttpServer server(8080,db,io_context);
        HttpServer server(8080,io_context);
        io_context.run();
    }
    catch(exception& e){
        cerr<<"Error while starting up the server: "<<e.what()<<endl;
        return 1;
    }
    return 0;
}
