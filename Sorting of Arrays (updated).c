#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do{

        while(A[i] <= pivot)
        {
            i++;
        }

        while(A[j] > pivot)
        {
            j--;
        } 

        if(i < j)
        {
            swap(&A[i], &A[j]);
        }
    }while(i < j);

    swap(&A[low], &A[j]);
    return j;
}


void quick_sort(int A[], int low, int high)
{
    int partition_index;
    if(low < high)
    {
        partition_index = partition(A, low, high);
        quick_sort(A, low, partition_index - 1);
        quick_sort(A, partition_index + 1, high);
    }
}


void bubble_sort(int A[], int n)
{
    int i, j, k, l;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < (n-i); j++)
        {
            if(A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
            }
        }

        for(l = 1; l < n-1; l++)
        {
            printf("The Array in %d iteration of pass %d is:\n", l, i);
            for(k = 0; k < n; k++)
            {
                printf("%d ", A[k]);
            }
            printf("\n");
        }

    }
}


void selection_sort(int A[], int n)
{
    int i, j, min, l, k;
    for(i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
            swap(&A[min], &A[i]);
        }

        for(l = 1; l < n-1; l++)
            {
                printf("The Array in %d iteration of pass %d is:\n", l, i+1);
                for(k = 0; k < n; k++)
                {
                    printf("%d ", A[k]);
                }
                printf("\n");
            }
        
    }
}


void insertion_sort(int A[], int n)
{
    int i, j, temp, k, l;
    for(i = 1; i < n; i++)
    {
        temp = A[i];

        for(j = i; j > 0 && temp < A[j-1]; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = temp;

        for(l = 1; l < n-1; l++)
        {
            printf("The Array in %d iteration of pass %d is:\n", l, i);
            for(k = 0; k < n; k++)
            {
                printf("%d ", A[k]);
            }
            printf("\n");
        }

    
    }
}


void merge(int A[], int mid, int low, int high)
{
    int i,j,k;
    int B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if(A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }  
    
    for(i = low; i <= high; i++)
    {
        A[i] = B[i];
    }

}


void merge_sort(int A[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

#define BUCKETS 10
void bucket_sort(int A[], int n)
{
    int i, j, k;
    int B[BUCKETS];
    
    for(j = 0; j < BUCKETS; j++)
    {
        B[j] = 0;
    }

    for(i = 0; i < n; i++)
    {
        ++(B[A[i]]);
    }

    for(i = 0, j = 0; j < BUCKETS; j++)
    {
        for(k = B[j]; k > 0; --k)
        {
            A[i++] = j;
        }
    }
}


int max_element(int A[], int n)
{
	int max = A[0], i;
	for(i = 1;i < n; i++)
	{
		if(A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}



void count(int * A, int n, int x)
{
    int count_array[n];
    int i;
    int count_array_2[100] = { 0 };

    for (i = 0; i < n; i++)
    {
        count_array_2[(A[i] / x) % 10]++;
    }

    for(i = 0; i < 100; i++)
    {
        count_array_2[i] += count_array_2[i - 1];
    }

    for(i = n - 1; i >= 0; i--)
    {
        count_array[count_array_2[(A[i] / x) % 10] - 1] = A[i];
        count_array_2[(A[i] / x) % 10]--;
    }

    for(i = 0 ; i < n; i++)
    {
         A[i] = count_array[i];
    }
}


void radix_sort(int A[], int n)
{
    int max = max_element(A, n);

    int x;

    for(x = 1; max / x > 0; x *= 10)
    {
        count(A, n, x);
    }
}


void shell_sort(int A[], int n)
{
    int gap, j, temp, i;

    for(gap = n/2; gap > 0; gap /= 2)
    {
        for(j = gap; j < n; j++)
        {
            temp = A[j];
            i = 0;

            for(i = j; (i >= gap) && (A[i - gap] > temp); i -= gap)
            {
                A[i] = A[i - gap];
            }

            A[i] = temp;

        }
    }
}


void count_sort(int * A, int n)
{
    int i, j, k, l;
    int max = max_element(A, n);
    int* count = (int *)malloc((max + 1)*sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;

    }

    i = 0;
    j = 0;

    while(i <= max)
    {
        if(count[i] > 0 )
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }

        else
        {
            i++;
        }

        for(l = 1; l < n-1; l++)
        {
            printf("The Array in %d iteration of pass %d is:\n", l, i);
            for(k = 0; k < n; k++)
            {
                printf("%d ", A[k]);
            }
            printf("\n");
        }
    }
}



int main()
{
    int n, i, choice = 1, task;
    
    double time_spent = 0.0;

    while (choice == 1)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int A[n];
        int low = 0, high = n-1;
        printf("\nEnter the elements of the array:\n");
        for(i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        printf("\nThe Given Array is:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
        
        printf("Enter the task you want to perform\n'1' for 'Quick Sort'\n'2' for 'Bubble Sort\n'3' for 'Selection Sort'\n'4' for 'Insertion Sort'\n'5' for 'Merge Sort'\n'6' for 'Bucket sort'\n'7' for 'Radix Sort'\n'8' for 'Shell Sort'\n'9' for 'Count Sort'\n");

        scanf("%d", &task);


        clock_t start = clock();
        switch (task)
        {
        case 1:
            quick_sort(A, low, high);
            break;
        case 2:
            bubble_sort(A, n);
            break;
        case 3:
            selection_sort(A, n);
            break;
        case 4:
            insertion_sort(A, n);
            break;
        case 5:
            merge_sort(A, low, high);
            break;
        case 6:
            bucket_sort(A, n);
            break;
        case 7:
            radix_sort(A, n);
            break;
        case 8:
            shell_sort(A, n);
            break;
        case 9:
            count_sort(A, n);
            break; 
        default:
            printf("Enter valid number: \n");
            break;
        }
        clock_t end = clock();

        time_spent += (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nThe sorted Array is:\n");
        for(i = 0; i < n; i++)
        {   
            printf("%d ", A[i]);
        }

        printf("\nThe execution time for selected sort is %f", time_spent );

        printf("\nDo you want to perform other sorts:\n'1' for 'Yes'\n'0' for 'No'\n");
        scanf("%d", &choice);

    }
    printf("\nExiting Program");
    Sleep(10);  
    return 0;
}
