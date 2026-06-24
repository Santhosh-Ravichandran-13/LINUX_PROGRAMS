#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {

    int sockfd;
    char buffer[1024];

    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP Server is Waiting...\n");

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&client_addr, &addr_len);

    printf("Received: %s\n", buffer);

    for(int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    sendto(sockfd, buffer, strlen(buffer), 0,
           (struct sockaddr *)&client_addr, addr_len);

    printf("Uppercase message sent.\n");

    close(sockfd);

    return 0;
}
