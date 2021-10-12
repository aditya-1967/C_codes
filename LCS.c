#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}


int lcs(char *x, char *y, int m, int n) 
{
    int t[m+1][n+1];
    int i, j;

    for(i = 0; i <=m; i++) 
    {
        for(j = 0; j <= n; j++) 
        {
            if(i == 0 || j == 0) 
            {
                t[i][j] = 0;
            }

            else if(x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            }

            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][n];
}


int main()
{
    int size1, size2;
    double time_spent = 0.0;
    
    char s1[] = "abcd";
    char s2[] = "abde";

    size1 = strlen(s1);
    size2 = strlen(s2);

    clock_t start = clock();
    printf("\nThe longest common subsequence is %d", lcs(s1, s2, size1, size2));
    clock_t end = clock();

     time_spent += (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nThe execution time of LCS is %f", time_spent );

    return 0;
}
