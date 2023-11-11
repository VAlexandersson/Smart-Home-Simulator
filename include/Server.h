#ifndef SMART_HOME_SIMULATOR_SERVER_H
#define SMART_HOME_SIMULATOR_SERVER_H


#include <netinet/in.h>
#include <asio.hpp>
#include <unordered_map>
#include <string>
#include <functional>
#include <csignal>
#include <thread>

class Server {
private:
    int server_fd; // file descriptor
    int new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    const int buffer_size = 1024;
    bool isRunning = false;
    std::unordered_map<std::string, std::function<void()>> commands;

public:
    Server();
    ~Server();
    void start();
    void stop();
    void run();
    void registerCommand(const std::string& command, std::function<void()> action);
};


#endif //SMART_HOME_SIMULATOR_SERVER_H
