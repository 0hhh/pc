#include <stdio.h>
#include <omp.h>
// OpenMP program to find 2nd smallest element in array
// gcc secondSmallest.c -o obj -fopenmp
// ./obj

int main()
{
    int numberOfElements, i, array[10000];
    
    printf("Enter the Number of Elements: ");
    scanf("%d", &numberOfElements);
    for (i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &array[i]);
    }

    int newArray[numberOfElements-1],distance;

    #pragma omp parallel for shared(distance)
    for (i = 0; i < numberOfElements-1; i++)
    {
        #pragma omp critical
        distance = array[i+1]-array[i];
        newArray[i]= distance;
    }

    printf(" \nadjecent distance arr is");
    for (i = 0; i < numberOfElements-1; i++)
        printf("\t  %d",newArray[i]);
    return 0; 
}