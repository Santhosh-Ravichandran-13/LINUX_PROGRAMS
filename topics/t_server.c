#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server_addr,
         sizeof(server_addr));

    listen(server_fd, 5);

    printf("Waiting for client connection...\n");

    client_fd = accept(server_fd,
                      (struct sockaddr *)&client_addr,
                      &addr_len);

    printf("Client Connected: %s\n",
           inet_ntoa(client_addr.sin_addr));

    FILE *fp = fopen("received.txt", "wb");

    if (fp == NULL) {
        printf("File cannot be created.\n");
        return 1;
    }

    while ((bytes_received =
            recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {

        fwrite(buffer, 1, bytes_received, fp);
    }

    printf("File Transfer Successful\n");

    fclose(fp);
    close(client_fd);
    close(server_fd);

    return 0;
}
