#include <stdio.h>
#include "functions.h"

int main(){
    printf("GCD of 12 and 8: %i\n", gcd(12, 8));
    printf("GCD of 11 and 7: %i\n", gcd(11, 7));
    printf("Absolute value of 6: %f\n", abs_val(6));
    printf("Absolute value of -6: %f\n", abs_val(-6));
    printf("Absolute value of 6.123: %f\n", abs_val(-6.123));
    printf("Absolute value of -6.123: %f\n", abs_val(-6.123));
}

int gcd(int int1, int int2){
    int smallest_number = (int1 > int2 ? int2 : int1);

    for (int i = smallest_number; i > 1; i--){
        if(int1 % i == 0 && int2 % i == 0){
            return i;
        }
    }

    return 1;
}

float abs_val(float value){
    if (value < 0){
        return 0 - value;
    }
    return value;
}