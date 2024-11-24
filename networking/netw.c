#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

void print_address_info(struct addrinfo *info) {
    char addr_str[INET6_ADDRSTRLEN]; // Buffer for IP address (IPv4/IPv6)
    void *addr;
    const char *ipver;

    if (info->ai_family == AF_INET) { // IPv4
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)info->ai_addr;
        addr = &(ipv4->sin_addr);
        ipver = "IPv4";
    } else if (info->ai_family == AF_INET6) { // IPv6
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)info->ai_addr;
        addr = &(ipv6->sin6_addr);
        ipver = "IPv6";
    } else {
        printf("Unknown address family.\n");
        return;
    }

    // Convert the IP address to a string
    inet_ntop(info->ai_family, addr, addr_str, sizeof(addr_str));
    printf("  %s: %s\n", ipver, addr_str);
}

int main() {
    struct addrinfo hints, *res, *p;
    int sockfd;
    int status;

    // Set up hints
    memset(&hints, 0, sizeof(hints)); // Zero out the struct
    hints.ai_family = AF_UNSPEC;      // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;  // TCP stream sockets

    // Get address info for "example.com" on port 80
    if ((status = getaddrinfo("example.com", "80", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    printf("IP addresses for example.com:\n");

    // Iterate through the linked list of results
    for (p = res; p != NULL; p = p->ai_next) {
        print_address_info(p);

        // Create a socket
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        // Attempt to connect
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        printf("Connected successfully!\n");
        break; // Exit the loop on successful connection
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to any address.\n");
        return 2;
    }

    freeaddrinfo(res); // Free the linked list
    close(sockfd);     // Close the socket

    return 0;
}
