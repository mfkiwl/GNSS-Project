
// Client side implementation of UDP client-server model 
// Visit https://www.geeksforgeeks.org/udp-server-client-implementation-c/ for more information
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT    4446
#define MAXLINE 1024 
#define IP "192.168.0.12"
  
// Driver code 
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = inet_addr(IP);
      
    int n, len; 
    while (1)
	{
		sendto(sockfd, (const char *)hello, strlen(hello), 
        MSG_EOR, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr));
		//printf("Hello message sent.\n");
	 }
	printf("Communication finished\n");
  
    close(sockfd); 
    return 0; 
} 
