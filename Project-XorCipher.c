#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned char *data, cipher[64];
	
	srand(time(0));
	unsigned int key = rand() % 255, index = 0;
	if (argv[1]) {
		data = argv[1];
	}
	else {
		return 0;
	}

	printf("original data: %s\n", data);

	while (data[index]) {
		cipher[index] = data[index] ^ key;
		index += 1;
	}
	
	printf("cipher text: ");
	index = 0;
	while (cipher[index]) {
		printf("%x:", cipher[index]);
		index += 1;
	}
	printf("\ndecrypted cipher text: ");
	index = 0;
	while (cipher[index]) {
		data[index] = cipher[index] ^ key;
		index += 1;
	}
	printf("%s", data);
	return 0;
}

