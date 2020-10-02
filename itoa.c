#include <stdio.h>
#include <stdlib.h>

unsigned int
power(int base, int raised_to)
{
	unsigned int answer = base;
	if (raised_to == 0) return 1;

	while (raised_to - 1) {
		answer *= base;
		raised_to -= 1;
	}
	return answer;
}

unsigned int
calculate_digits(unsigned int num)
{
	int index = 1, digits = 1;
	while (index < 4) {
		if ((num / power(10, index)) > 0) {
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

		curr_digit = (num % power(10, index)) / power(10, index - 1);
		string[string_index] = 48 + curr_digit;
		string_index += 1;
		index -= 1;
	}

	return string;
}

int main()
{
	int calls = 4;
	char IP[16];
	while (calls > 0) {
		sleep(1);
		srand(time(0));
		unsigned int current = rand() % 255;
		strcat(IP, int_to_string(current));
		if (calls > 1)
			strcat(IP, ".");
		calls -= 1;
	}
	printf("IP: %s", IP);
	return 0;
}

