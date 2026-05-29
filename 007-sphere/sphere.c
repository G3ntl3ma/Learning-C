// calculate the volume of a sphere with the value given by the user

#include <stdio.h>

#define PI 3.141f

int main(void){
    int radius;
    printf("Please enter the radius of the sphere: ");
    scanf("%d", &radius);
    printf("The volume of the sphere is: %f\n", 4.0f/3.0f * PI * radius * radius * radius);
    return 0;
}