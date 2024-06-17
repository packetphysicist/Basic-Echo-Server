#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 3000
#define BUFFERSIZE 1024

int main(void) {
   struct sockaddr_in client_address;
   struct sockaddr_in serv_address;
   serv_address.sin_family = AF_INET;
   serv_address.sin_addr.s_addr = INADDR_ANY;
   serv_address.sin_port = htons(PORT);

   char buffer[BUFFERSIZE];
   int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

   if (sockfd < 0) {
      perror("Socket creation failed.\n");
      return 1;
   } else {
      printf("Socket created.\n");
   }
   
   if (bind(sockfd, (struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
      perror("Socket binding failed.\n");
      return 1;
   } else {
      printf("Socket bound.\n");
   }

   int n;
   socklen_t len;
   len = sizeof(client_address);

   n = recvfrom(sockfd, (char *)buffer, BUFFERSIZE,  MSG_WAITALL, ( struct sockaddr *) &client_address, &len); 

   buffer[n] = '\0';
   printf("Received: %s", buffer);

   sendto(sockfd, &buffer, strlen(buffer),  
        MSG_CONFIRM, (const struct sockaddr *) &client_address, 
            len); 
   printf("Sent: %s", buffer);

   close(sockfd);
   exit(0);
};