#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#include <sys/types.h>
#include <sys/socket.h> //socket AF_INET SOCK_STREAM
#include <netinet/in.h> //sockaddr_in
#include <arpa/inet.h> // inet_ntop()
#include <time.h>

int main(void)
{
	int clifd;
	struct sockaddr_in servaddr;
	char buff[100];

	clifd = socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&servaddr, sizeof(struct sockaddr_in));
	bzero(buff, 100);
	strcpy(buff, "127.0.0.1");
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, buff, &servaddr.sin_addr);
	servaddr.sin_port = htons(1333);

	//bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	//listen(listenfd, 10);

	connect(clifd, (struct sockaddr*)&servaddr, sizeof(servaddr));
//	for(;;)
	{
		read(clifd, buff, 100);
		printf("recv from server: %s\n", buff);
	}
	close(clifd);

	return 0;
}

