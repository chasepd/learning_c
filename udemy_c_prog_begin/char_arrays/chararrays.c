#include <stdio.h>

#include "chararrays.h"


int main(){
    printf("There are %i characters in the word 'Snufalufagus'\n", strlen_custom("snufalufagus"));
    printf("There are %i characters in the phrase 'Snufalufagus rides again'\n", strlen_custom("Snufalufagus rides again"));

    char result[100];

    strcat_custom(result, "super", "duper");

    printf("Appending 'super' and 'duper' results in %s\n", result);

    return 0;
}

int strlen_custom(char str[]){
    char current = str[0];
    int count = 0;

    while (current != '\0'){
        count++;
        current = str[count];
    }

    return count;
}

void strcat_custom(char result[], const char str1[], const char str2[]){
    char current = str1[0];
    int count = 0;

    while (current != '\0'){
        result[count] = str1[count];
        count++;
        current = str1[count];
    }

    int index = count;
    current = str2[0];
    count = 0;

    while (current != '\0'){
        result[index] = str2[count];
        count++;
        index++;
        current = str2[count];
    }

    result[index] = '\0';
}
