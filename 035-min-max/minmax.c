//Find the largest and smallest elements in an array

#include <stdio.h>

#define N 10

void MaxMin(int a[], int n, int *max, int *min);

int main(void){
    int b[N], i, big, small;

    printf("Enter %d Numbers: ", N);
    for(i = 0; i < N; i++){
        scanf("%d", &b[i]);
    }

    MaxMin(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void MaxMin(int a[], int n, int *max, int *min){
    int i;

    *max = *min = a[0];
    for(i = 0; i < n; i++){
        if(a[i] > *max){
            *max = a[i];
        } else if(a[i] < *min){
            *min = a[i];
        }
    }
}