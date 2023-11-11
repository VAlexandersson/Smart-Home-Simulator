#include "Server.h"
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <utility>

Server::Server() {
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if((setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    std::cout << "Server created" << std::endl;
}

Server::~Server() {
    close(server_fd);
}

void Server::start() {
    isRunning = true;
    std::thread serverThread(&Server::run, this);
    serverThread.join();
}

void Server::stop() {
    isRunning = false;
}

void Server::run() {
    while (isRunning) {
        std::cout << "Server listening..." << std::endl;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        char buffer[1024] = {0};
        long valread = read(new_socket, buffer, 1024);
        std::string command(buffer, valread);
        std::cout << "Received command: " << command << std::endl;

        if (commands.find(command) != commands.end()) {
            commands[command]();
        } else {
            std::cout << "Command not found" << std::endl;
        }
    }
}

void Server::registerCommand(const std::string& command, std::function<void()> action) {
    commands[command] = std::move(action);
}
