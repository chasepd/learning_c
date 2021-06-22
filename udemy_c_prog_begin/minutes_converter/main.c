#include <stdio.h>

int main(){

    int minutes = 60*24;


    float days = minutes / (60.0 * 24.0);
    float years = minutes / (365.0 * (60.0 * 24.0));

    printf("\nDays:%f\n", days);
    printf("\nYears:%f\n", years);
    return 0;
}