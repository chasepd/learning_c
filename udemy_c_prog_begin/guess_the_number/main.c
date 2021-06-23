#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
            char result[7];
            if(guess > correct_number){
                strcpy(result, "lower");
            }
            else{
                strcpy(result, "higher");
            }
            printf("Incorrect guess. The correct number is %s than that. You've used %i out of 5 guesses.\n", result, count + 1);
            if(count == 4){
                printf("GAME OVER. The correct number was %i.\n", correct_number);
            }
        }
    }

    return 0;
}