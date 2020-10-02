#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PRINT_MAC(mac) printf("%x:%x:%x:%x:%x:%x\n", \
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5])

int main()
{
	int count = 8, index = 0;
	unsigned char mac[8], curr_byte[2];
	unsigned int current;
	unsigned int hexcodes[256];

	srand(time(0));
	while (count) {
		current = rand() % 256;
		mac[index] = current;	
		index += 1;
		count -= 1;
	}
	PRINT_MAC(mac);
}

