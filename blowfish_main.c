#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DATASIZE 32
#define CHUNKSIZE 8

int main(int argc, char **argv)
{
	/* these are the function args */
	char data[DATASIZE];
	char *buffer;
	int original_size, padded_size;
	int i = 0, padbytes = 0;
	unsigned int left = 0x00000000, right = 0x00000000;


	/* input configuration */
	fgets(data, DATASIZE, stdin);
	original_size = strlen(data) - 1;
	data[original_size] = '\0';

	/* padded string configuration */
	padded_size   = ceil(original_size / 8.0) * 8;
	buffer        = malloc(sizeof(char) * padded_size);
	padbytes      = padded_size - original_size;
	
	/* copying data into the buffer and padding it */
	if (strncpy(buffer, data, original_size) != buffer) {
		printf("copying the data failed\n");
		return 0;
	}
	
	/* padding the buffer string */
	if (memset(buffer + original_size, padbytes, sizeof(char) * 
				(padbytes)) != buffer + original_size) {
		printf("memset failed\n");
		return 0;
	}
	
	/* printing the buffer string for verification */
	printf("hex form of buffer string is\n");
	i = 0;
	while (i < padded_size) {
		printf("%.2X%.2X%.2X%.2X ", buffer[i], buffer[i + 1], buffer[i + 2],
				buffer[i + 3]);
		i += 4;
	}
	printf("\n");
	
	/* zero out the whole string, so that we're not cheating at all */
	memset(data, 0x00, original_size);

	/* again move the unpadded version of string into a buffer */
	memmove(data, buffer, original_size);
	data[original_size] = '\0';

	/* voila, you're a genius */
	printf("original string: %s\n", data);

	free(buffer);
	return 0;	
}
