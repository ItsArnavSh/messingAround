#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main() {
    uint32_t file_size = 1024;  // Host Byte Order
    uint32_t net_file_size = htonl(file_size); // Convert to Network Byte Order

    printf("Host Byte Order: %u\n", file_size);
    printf("Network Byte Order: %u\n", net_file_size);

    // Pretend we're sending net_file_size over the network...

    // On the receiving side:
    uint32_t received_size = ntohl(net_file_size); // Convert back to Host Byte Order
    printf("Received Host Byte Order: %u\n", received_size);

    return 0;
}
