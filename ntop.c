#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>

unsigned int
calculate_digits(unsigned int num)
{
	int index = 1, digits = 1;
	while (index < 4) {
		if ((num / (unsigned int)pow(10, index)) > 0) {
			index += 1;
			digits += 1;
		}
		else break;
	}
	
	return digits;
}

char *
int_to_string(unsigned int num)
{
	unsigned int digits = calculate_digits(num), index, curr_digit,
	    string_index = 0;

	index = digits;
	char *string = malloc(sizeof *string * (digits + 1));
	
	while (index > 0) {
		curr_digit = (num % (unsigned int)pow(10, index)) / 
				(unsigned int)pow(10, index - 1);
		string[string_index] = 48 + curr_digit;
		string_index += 1;
		index -= 1;
	}

	return string;
}

int
main()
{
	/* 192.168.1.154 */
	char initial[16];
	scanf("%s", &initial);
	unsigned int address = inet_pton(AF_INET, initial, &address), buffer;
	address = htonl(address);
	printf("initial in hex: %x", address);
	char IP[16];
	char *current_octet;

	for (int i = 0; i < 4; i++) {
		buffer = address;
		buffer <<= 24 - 8*i;
		buffer >>= 24;

		current_octet = int_to_string(buffer);
		strncat(IP, current_octet, strlen(current_octet));

		if (i < 3) strncat(IP, ".", 2);
	}
	printf("IP address in string is: %s\n", IP);

	return 0;
}
