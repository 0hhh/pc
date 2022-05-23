#include <stdio.h>
#include <omp.h>
// OpenMP program to find 2nd smallest element in array
// gcc secondSmallest.c -o obj -fopenmp
// ./obj

int main()
{
    int numberOfElements, i, array[10000];
    int smallest, secondsmallest;
    
    printf("Enter the Number of Elements: ");
    scanf("%d", &numberOfElements);
    for (i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &array[i]);
    }

    if (array[0] < array[1]) {
        smallest = array[0];
        secondsmallest = array[1];
    }
    else {
      smallest = array[1];
      secondsmallest = array[0];
    }

    #pragma omp parallel for shared(smallest)
    for (i = 2; i < numberOfElements; i++)
    {
        #pragma omp critical
        if (array[i] < smallest) {
        secondsmallest = smallest;
        smallest = array[i];
        }
        else if (array[i] < secondsmallest) {
            secondsmallest = array[i];
        }
    }

    printf(" \nSecond smallest element is %d", secondsmallest);
    return 0; 
}