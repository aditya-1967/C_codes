#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int mcm(int arr[], int size) 
{
    int t[size-1][size-1];
    int i, j, k, gap, min;
    int left_cost, right_cost, multi_cost, total_cost;

    for(gap = 0; gap < size - 1; gap++)
    {
        for(i = 0, j = gap; i < size - 1; i++, j++)
        {
            if(gap == 0)
            {
                t[i][j] = 0;
            }
            else if(gap == 1)
            {
                t[i][j] = arr[i] * arr[j] * arr[j + 1];
            }
            else
            {
                min = INT_MAX;
                for(k = i; k < j; k++)
                {
                    left_cost = t[i][k];
                    right_cost = t[k+1][j];
                    multi_cost = arr[i] * arr[k+1] * arr[j+1];
                    total_cost = left_cost + right_cost + multi_cost;

                    if(total_cost < min)
                    {
                        min = total_cost;
                    }
                }

                t[i][j] = min;
            }
        }
    }
    return t[0][size - 2];    

}



int main()
{
    int n, i, size;
    double time_spent = 0.0;

    printf("Enter the dimension of array: ");
    fflush(stdout);
    scanf("%d", &n);

    int A[n];

    printf("\nEnter the element of array: ");
    fflush(stdout);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    size = sizeof(A) / sizeof(A[0]);

    clock_t start = clock();
    printf("\nMinimum cost of MCM is %d", mcm(A, size));
    clock_t end = clock();

    time_spent += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nThe execution time of MCM is %f", time_spent );

    return 0;
    
}