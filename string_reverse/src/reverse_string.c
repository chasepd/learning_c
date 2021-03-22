#include <stdio.h>
#include <string.h>

void print_usage(){
	printf("Usage: string_reverse string_to_reverse\n");
}

int main( int argc, char *argv[] ){
	if (argc > 2) {
		printf("Too many arguments provided.\n");
		print_usage();
	}
	else if (argc < 2){
		printf("Too few arguments provided.\n");
		print_usage();
	}
	else {
		int length = (int)strlen(argv[1]);
		printf("Reversing string %s of length %i\n", argv[1], length);
		char rev[length + 1];
		for (int counter = 0; counter < length; counter++){
			rev[counter] = argv[1][length - 1 - counter];
		}
		rev[length] = '\0';
		printf("Reversed string: %s\n", rev);
	}
}
