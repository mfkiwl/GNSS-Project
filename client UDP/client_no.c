
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
#include "client.h"
#include "cJSON-master/cJSON.h"
  
#define PORT    4446
#define MAXLINE 1024 
#define IP "192.168.1.12"
  
int main()
{
	printf("Main function");
	sendToServer();
	char *string = createJSON();
	fprintf(stderr, string);
	return 0;
}

// Driver code 
void sendToServer() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
	char *json_out;
  
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
    //return 0; 
} 

char* createJSON()
{
	// observables: Doppler, carrier_phase, code_freq, CN0
	int observables_values[4] = { 1000, 502, 111, 34};
	
	cJSON *rx_timestamp = NULL;
    cJSON *PRN = NULL;
	cJSON *observables = NULL;
	cJSON *Doppler_freq = NULL;
	cJSON *carrier_phase = NULL;
	cJSON *code_freq = NULL; 
	cJSON *CN0 = NULL;
	char *output = NULL;
	
	
    cJSON *monitor = cJSON_CreateObject();
    if (monitor != NULL)
    {
		rx_timestamp = cJSON_CreateString("2020-01-06");
		if (rx_timestamp != NULL)
		{
			cJSON_AddItemToObject(monitor, "rx_timestamp", rx_timestamp);
			PRN = cJSON_CreateString("E22");
			if (PRN != NULL)
			{
				cJSON_AddItemToObject(monitor, "PRN", PRN);
			}
			observables = cJSON_CreateArray();
			if (observables != NULL)
			{
				cJSON_AddItemToObject(monitor, "observables", observables);
				/*for (index = 0; index < (sizeof(observables_values) / (2 * sizeof(int))); ++index)
				{
					
				}*/
			}
		}
				
		output = cJSON_Print(monitor);
		if (output == NULL)
		{
			fprintf(stderr, "Failed to print monitor.\n");
		}
		else
		{
			cJSON_Delete(monitor);
			return output;
		}
    		
	}
	else
	{
		fprintf(stderr, "Failed monitor creation\n");
	}	
}
