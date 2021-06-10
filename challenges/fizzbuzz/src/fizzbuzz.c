#include <stdio.h>

int main(){
	for ( int number = 1; number <= 100; number++ ){
		if (number % 3 == 0){
			if( number % 5 == 0 ){
				printf("FizzBuzz\n");
			}
			else{
				printf("Fizz\n");
			}
		}
		else if (number % 5 == 0){
			printf("Buzz\n");
		}
		else{
			printf("%i\n", number);
		}
	} 
	return 0;
}
