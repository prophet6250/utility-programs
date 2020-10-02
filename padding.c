#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

int main() {
	char unpadded[SIZE], padded[SIZE];
	fgets(padded, SIZE, stdin);
	int i = 0, size = strlen(padded), padsize;
	memset(padded + size - 1, 8 - size, sizeof *padded * (8 - size + 1));
	while (i < 8) {
		printf("%X ", padded[i]);
		i += 1;
	}
	printf("now unpadding this string\n");
	padsize = ceil(size / 8.0) * 8;	
	padcount = padded[size];
	
	printf("\n");
	return 0;
}
