/* 
 * the headers are usually in the format of key:value except the first line
 * sample http request: 
 *
 * POST /api/login HTTP/1.1\r\n         ---this is the only line without the k,v pair
 * Host: example.com\r\n                ---request headers
 * Content-Type: application/json\r\n   ---representation headers for the body
 * Content-Length: 39\r\n               ---representation headers for the body
 * \r\n                                 ---empty line represting the headers are done
 * {"username":"bob",                   ---body
 * "password":"secret"}                 ---body
 */
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <map>
#include <boost/asio.hpp>

struct HttpRequest {
    std::string method;
    std::string target;
    std::string version;
    std::map<std::string,std::string> headers;
    std::string body;
};


HttpRequest parseRequest(boost::asio::ip::tcp& socket);
#endif
