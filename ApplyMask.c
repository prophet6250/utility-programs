#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	unsigned int b_IP, b_mask, b_masked_IP;
	char s_IP[16], s_masked_IP[16];
	char c_mask;
	
	if (argc < 2) {
		printf("error! enter valid IP address in the arguments!\n");
		return 1;
	}

	printf("enter the number of masked bits\n");
	scanf("%d", &c_mask);

	strncpy(s_IP, argv[1], 16);

	/* direct calculation of binary subnet mask was not producing correct
	 * results, i.e, b_mask = 0xffffffff << (32 - c_mask); wasn't working.
	 * this loop basically converts 0xffffffff into the required binary
	 * subnet mask
	 */
	b_mask = 0xffffffff << (32 - c_mask); 

	inet_pton(AF_INET, s_IP, &b_IP);	
	b_IP = htonl(b_IP);
	
	printf("subnet mask in hex: %x\n", b_mask);
	printf("initial IP in string form: %s, in hex form: %x\n", s_IP, b_IP);

	/* simple ANDing */
	b_masked_IP = b_mask & b_IP;

	b_masked_IP = ntohl(b_masked_IP);
	inet_ntop(AF_INET, &b_masked_IP, s_masked_IP, 16);
	/* this may be unnecessary/redundant on your machine, check the output
	 * and remove this call accordingly */
	b_masked_IP = htonl(b_masked_IP);

	printf("masked IP in binary form: %x, in string form: %s\n", b_masked_IP,
			s_masked_IP);

	return 0;
}

