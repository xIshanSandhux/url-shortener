#ifndef SERVER_HPP
#define SERVER_HPP

class Database;

class HttpServer{
    private:
        Database &db_;
        int port_;

    public:
        HttpServer(int port, Database& db);
        void run_server();
};

#endif 
