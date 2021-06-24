#include <stdio.h>

#define YEARS 5
#define MONTHS 12

int starting_year = 2014;

float rainfall_history[YEARS][MONTHS] = {
    {2.9, 1.2, 4.5, 3.2, 2.1, 1.1, 1.6, 0.4, 1.6, 3.3, 2.9, 4.5},
    {1.8, 1.5, 3.7, 4.3, 2.8, 2.6, 1.0, 1.1, 0.8, 2.2, 1.8, 3.4},
    {3.0, 2.1, 5.3, 5.8, 3.3, 2.2, 2.2, 0.9, 3.0, 3.1, 2.2, 6.2},
    {1.9, 1.3, 1.6, 2.2, 1.2, 1.0, 1.0, 0.1, 0.6, 1.5, 1.2, 0.5},
    {2.6, 1.1, 4.8, 3.3, 2.2, 1.8, 1.6, 0.4, 1.6, 3.3, 2.9, 4.7}
};

float month_averages[MONTHS] = {};

int main(){
    float yearly_average = 0;
    int current_year = starting_year;
    printf("YEAR\t\tRAINFALL\n");
    for (int year_num = 1; year_num < YEARS; year_num++){
        float * year = rainfall_history[year_num];
        float yearly_rainfall = 0;

        for (int month_num = 0; month_num < MONTHS; month_num++){
            yearly_rainfall += year[month_num];
            month_averages[month_num] = (month_averages[month_num] + year[month_num]) / (year_num + 1);
        }
        yearly_average += yearly_rainfall;
        printf("%i\t\t%f\n", current_year, yearly_rainfall);
        current_year++;
    }

    yearly_average = yearly_average / YEARS;
    printf("\nThe yearly average is %f inches.\n", yearly_average);
    printf("\nMONTHLY AVERAGES:\n");
    printf("JAN\tFEB\tMAR\tAPR\tMAY\tJUN\tJUL\tAUG\tSEP\tOCT\tNOV\tDEC\n");

    for(int month_num = 0; month_num < MONTHS; month_num++){
        if(month_num == MONTHS - 1){
            printf("%.2f\n", month_averages[month_num]);
        }
        else{
            printf("%.2f\t", month_averages[month_num]);
        }
    }

    return 0;
}