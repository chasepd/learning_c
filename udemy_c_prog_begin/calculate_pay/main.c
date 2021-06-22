#include <stdio.h>

#define PAY_RATE 12.0
#define TAX_BRACKET_1 0.15
#define TAX_BRACKET_2 0.20
#define TAX_BRACKET_3 0.25

int main(){

    float hours_worked = 0.0;

    printf("Enter the number of hours worked: ");
    scanf("%f", &hours_worked);

    float total_pay = 0.0;

    if(hours_worked > 40.0){
        total_pay = PAY_RATE * 40.0;
        float overtime_hours = hours_worked - 40.0;
        total_pay += PAY_RATE * 1.5 * overtime_hours;
    }
    else{
        total_pay = PAY_RATE * hours_worked;
    }
    
    printf("Gross pay for this pay period is: %.2f\n", total_pay);
    
    float taxes = 0.0;
    if(total_pay > 450.0){
        taxes = TAX_BRACKET_1 * 300.0;
        taxes += TAX_BRACKET_2 * 150.0;
        taxes += TAX_BRACKET_3 * (total_pay - 450);
    }
    else if (total_pay > 300){
        taxes = TAX_BRACKET_1 * 300.0;
        taxes += TAX_BRACKET_2 * (total_pay - 300);
    }
    else{
        taxes = TAX_BRACKET_1 * total_pay;
    }

    printf("Taxes for this pay period are: %.2f\n", taxes);
    printf("Net pay for this pay period is: %.2f\n", total_pay - taxes);
    return 0;
}