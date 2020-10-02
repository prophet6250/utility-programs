#include <stdio.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(0));
	unsigned int address = rand();
	char IP[16];
	
	inet_ntop(AF_INET, &address, IP, 16);
	printf("%s\n", IP);

	return 0;
}
