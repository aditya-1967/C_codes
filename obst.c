#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int sum(int freq[], int i, int j)
{
    int s = 0;
    int k;

    for(k = i; k <= j; k++)
    {
        s += freq[k];
    }
    return s;
}


int obst(int keys[], int freq[], int n)
{
    int cost[n][n];
    int i, j, k, r, c;

    for(i = 0; i < n; i++)
    {
        cost[i][i] = freq[i];
    }

    for(k = 2; k <= n; k++)
    {
        for(i = 0; i < n-k+1; i++)
        {
            j = i + k - 1;
            cost[i][j] = INT_MAX;

            for(r = i; r <= j; r++)
            {
                c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                } 
            }
        }
    }
    return cost[0][n-1];
}


int main()
{
    int n, i, size;
    double time_spent = 0.0;

    printf("\nEnter the size of array: ");
    scanf("%d", &n);

    int keys[n];
    int freq[n];

    printf("Enter the keys: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);
    }

    printf("\nEnter the freq: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &freq[i]);
    }

    size = sizeof(keys)/sizeof(keys[0]);

    clock_t start = clock();
    printf("\nThe cost of optimal BST is: %d", obst(keys, freq, size));
    clock_t end = clock();

    time_spent += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nThe execution time of OBST is %f", time_spent );
    return 0;
}