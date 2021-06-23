#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    __time_t t;

    srand((unsigned) time(&t));
    int correct_number = rand() % 21;
    
    for (int count = 0; count < 5; count++){
        printf("Enter a number between 0 and 20: ");
        int guess;
        scanf("%i", &guess);

        if (guess > 20 || guess < 0){
            printf("Number outside given range.\n");
            count--;
            
        }
        else if (guess == correct_number){
            printf("You win!\n");
            break;
        }
        else{
            printf("Incorrect guess. You've used %i out of 5 guesses.\n", count + 1);
            if(count == 4){
                printf("GAME OVER. The correct number was %i.\n", correct_number);
            }
        }
    }

    return 0;
}