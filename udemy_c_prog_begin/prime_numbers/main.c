#include <stdio.h>

#define ARRAY_LENGTH 50

int primes[ARRAY_LENGTH] = {2, 3};

int main(){
    int current_primes_index = 2;
    printf("2\n3\n");
    for (int num = 4; num <= 100; num++){
        int is_prime = 1;

        for (int index = 0; index < ARRAY_LENGTH; index++){
            if (primes[index] == 0){
                break;
            }
            else if (num % primes[index] == 0){
                is_prime = 0;
                break;
            }
        }

        if (is_prime){
            primes[current_primes_index] = num;
            current_primes_index++;
            printf("%i\n", num);
        }
    }

}