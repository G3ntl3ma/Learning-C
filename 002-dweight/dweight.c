/*  Computes the dimesional weight of a 12" x 10" x 8" box 
    with input provided by the user */

#include <stdio.h>

int main(void){
    int height, length, width, volume, weight;
    printf("Enter height of the box: ");
    scanf("%d", &height);
    printf("Enter length of the box: ");
    scanf("%d", &length);
    printf("Enter width of the box: ");
    scanf("%d", &width);
    volume = height * length * width;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (Cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds) : %d\n", (volume + 165) / 166);

    return 0;
}