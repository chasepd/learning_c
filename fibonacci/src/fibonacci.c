#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void print_usage(){
	printf("Usage: fibonacci number_to_print\n");
}

bool is_number(char number[]){
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}


int main( int argc, char *argv[] ){
	if (argc > 2) {
		printf("Too many arguments provided.\n");
		print_usage();
		return 1;
	}
	else if (argc < 2){
		printf("Too few arguments provided.\n");
		print_usage();
		return 1;
	}

	int number_to_print = atoi(argv[1]);

	if (!is_number(argv[1])){
		printf("Invalid input, number_to_print must be an integer.\n");
		return 2;
	}
	else {
		if (number_to_print > 47){
			printf("47 is the largest index of the sequence that is supported. Defaulting to number_to_print = 47.....\n");
			number_to_print = 47;
		}
		printf("Printing first %i numbers in the Fibonacci sequence......\n", number_to_print);

		int two_previous = 0;
		int one_previous = 0;

		for (int counter = 0; counter < number_to_print; counter++){
			if (counter == 0){
				printf("0 ");
			}
			else if (counter == 1){
				printf("1 ");
				one_previous = 1;
			}
			else {
				int new_number = two_previous + one_previous;
				printf("%i ", new_number);
				two_previous = one_previous;
				one_previous = new_number;
			}
		}
		printf("\n");
	}
	return 0;
}
