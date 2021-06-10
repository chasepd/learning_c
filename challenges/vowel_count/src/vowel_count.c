#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_usage(){
	printf("Usage: vowel_count text\n");
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
		printf("Too many arguments provided. Did you put spaces in your text without quotations?\n");
		print_usage();
		return 1;
	}
	else if (argc < 2){
		printf("Too few arguments provided.\n");
		print_usage();
		return 1;
	}

	char *text = argv[1];
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;

	int length = strlen(text);
	for ( int index = 0; index < length; index++ ){
		char character = tolower(text[index]);
		if (character == 'a'){
			a++;
		}
		else if (character == 'e'){
			e++;
		}
		else if (character == 'i'){
			i++;
		}
		else if (character == 'o'){
			o++;
		}
		else if (character == 'u'){
			u++;
		}
	}
	
	printf("==========CHARACTER REPORT==========\na: %i\ne: %i\ni: %i\no: %i\nu: %i\n", a, e, i, o, u);

	return 0;
}
