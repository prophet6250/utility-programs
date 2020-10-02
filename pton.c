#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	/* given an string of IP, convert it to integer form */
	char IP[16];
	strncpy(IP, argv[1], strlen(argv[1]));
	char *octet,
	     *buffer = IP;
	unsigned int address = 0, octet_count = 0;

	while (octet = strtok_r(buffer, ".", &buffer)) {
		if (octet_count < 4) {
			address <<= 8;
			octet_count += 1;
		}

		address |= atoi(octet);
	}

	printf("binary address : %x\n", address);
	return 0;
}
