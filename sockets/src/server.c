#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    int server_fd;
    int client_socket;
    int opt = 1;
    char buffer[1024] = { 0 };
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0
        ||setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))
        || bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0
        || listen(server_fd, 3) < 0
        || (client_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
        perror("terminated");
        exit(EXIT_FAILURE);
    }

    read(client_socket, buffer, 1024 - 1);
    printf("received: %s\n", buffer);

    close(client_socket);
    close(server_fd);
    return 0;
}
