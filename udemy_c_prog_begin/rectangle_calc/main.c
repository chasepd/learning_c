#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
    if (argc != 3){
        printf("USAGE: rectangle_calc height width\n");
        return 1;
    }

    float height = atof(argv[1]);
    float width = atof(argv[2]);

    float perimeter = 2 * (height + width);
    float area = height * width;

    printf("The perimeter of the rectangle is %f\n", perimeter);
    printf("The area of the rectangle is %f\n", area);

    return 0;
}
