#include <stdio.h>
#include <string.h>
#include "reverse.h"

int main(){
    char input[1000];
    memset(input, '\0', 1000);

    printf("Enter string: ");
    scanf("%[^\n]", input);

    reverse(input);

    printf("\n%s\n", input);
}

void reverse(char * input){
    int string_length = strlen(input);

    char holder[string_length + 1];
    strcpy(holder, input);

    for(int i = 1; i <= string_length; i++){
        input[i - 1] = holder[string_length - i]; 
    }

    input[string_length] = '\0';
}