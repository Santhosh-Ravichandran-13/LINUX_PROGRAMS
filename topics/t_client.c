#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int sock;
    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];
    int bytes_read;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1",
              &server_addr.sin_addr);

    connect(sock,
           (struct sockaddr *)&server_addr,
           sizeof(server_addr));

    FILE *fp = fopen("sample.txt", "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while ((bytes_read =
            fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {

        send(sock, buffer, bytes_read, 0);
    }

    printf("File Transfer Successful\n");

    fclose(fp);
    close(sock);

    return 0;
}
