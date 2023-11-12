#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
 
int main(int argc, char const* argv[]) {
    const char* data = "#1 data chunk";
    int client_fd;
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(serv_addr.sin_family, "127.0.0.1", &serv_addr.sin_addr);

    if ((client_fd = socket(serv_addr.sin_family, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create a socket.");
        return -1;
    }

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect");
        return -1;
    }

    send(client_fd, data, strlen(data), 0);
    printf("sent: %s", data);

    close(client_fd);
}