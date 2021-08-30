#include<stdio.h>
#include<stdlib.h>



void insertion_sort(int array[], int size)
{
	int i, j, temp;
	for(i=1;i< size; i++)
	{
		temp = array[i];
		j = i-1;
		while(j>=0 && array[j] > temp)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}




void quick_sort(int array[], int lb, int ub)
{
	int i, j, pivot, temp;
	if(lb<ub)
	{
		pivot = lb;
		i = lb;
		j = ub;
	
	
	while(i<j)
	{
		while(array[i]<=array[pivot]&&i<ub)
		{
			i++;
		}
		while(array[j]>array[pivot])
		{
			j--;
		}
		if(i<j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		
	}
	
		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		quick_sort(array, lb, j-1);
		quick_sort(array, j+1, ub);
	}
}


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void selection_sort(int array[], int size)
{
	int i, mid, j;
	for(i=0; i<(size -1); i++)
	{
		mid = i;
		for(j=i+1;j<size;j++)
		{
			if(array[j] < array[mid])
			{
				mid =j;
			}
		}
		swap(&array[mid], &array[i]);
	}
}

void merge(int array[], int lb, int mid, int ub)
{
	int i,j,k;
	int a = mid - lb + 1;
	int b = ub - lb;
	int b_array[a], c_array[b];
	for(i=0; i<a; i++)
	{
		b_array[i] = array[lb + i];
	}
	for(j=0; j< b; j++)
	{
		c_array[j] = array[mid + lb + j];
	}
	
	i = 0;
	j = 0;
	k = lb;
	
	while(i< a && j < b)
	{
		if(b_array[i] <= c_array[j] )
		{
			array[k] = b_array[i];
			i++;
		}
		else
		{
			array[k] = c_array[j];
			j++;
		}
		k++;
	}
	while(i < a)
	{
		array[k] = b_array[i];
		i++;
		k++; 
	}
	while(j < b)
	{
		array[k] = c_array[j];
		j++;
		k++;
	}
}


void merge_sort(int array[], int lb, int ub)
{
	if(lb < ub)
	{
		int mid = lb + (ub -1)/2;
		merge_sort(array, lb, mid);
		merge_sort(array, mid+1, ub);
		merge(array, lb,mid, ub);
	}
}


void bubble_sort(int array[], int size)
{
	int i, j, temp, flag;
	for(i=0;i<(size-1); i++)
	{
		flag = 0;
		for(j=0; j<(size-1-i); j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = 1;
			}
		}
		if(flag ==0)
		{
			break;
		}
	}
}


void shell_sort(int array[], int size)
{
	int gap, i, j, temp;
	for(gap = size/2; gap>0; gap/= 2)
	{
		for(i= gap; i < size; i++)
		{
			temp = array[i];
			for(j=i; j>= gap && array[j - gap]>temp; j-=gap)
			{
				array[j] = array[j=gap];
			}
			array[j] = temp;
		}
	}
}


void bucket_sort(int array[], int size)
{
	int i,j;
	int a[size];
	for(i=0; i<size; i++)
	{
		a[i] = 0;
 	}
 	for(i = 0; i < size; i++)
 	{
 		(a[array[i]])++;
	}
	for(i=0, j=0;i< size;i++)
	{
		for(;a[i]>0;(a[i])--)
		{
			array[j++] = i;
		}
	}
	
}

int max(int array[], int size)
{
	int m = array[0], i;
	for(i = 1;i< size; i++)
	{
		if(array[i] > m)
		{
			m = array[i];
		}
	}
	return m;
}


void count_sort(int array[], int size, int exp)
{
	int op[size];
	int i, count[10]= {0};
	for(i=0;i<size;i++)
	{
		count[(array[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i] += count[i-1];
	}
	for(i=size-1;i>=0;i--)
	{
		op[count[(array[i]/exp)%10]-1] = array[i];
		count[(array[i]/exp)%10]--;
	}
	for(i=0; i<size; i++)
	{
		array[i] = op[i];
	}
}


void radix_sort(int array[], int size)
{
	int m = max(array, size);
	int exp;
	for(exp = 1;m/exp>0;exp*=10)
	{
		count_sort(array, size, exp);
	}
}


int temp;

void heapify(int array[], int size, int i)
{
	int large = i;
	int lb = 2*i + 1;
	int ub = 2*i + 2;
	if(lb<size && array[lb]>array[large])
	{
		large = lb;
	}
	if(ub<size && array[ub]>array[large])
	{
		large = ub;
	}
	if(large != i)
	{
		temp = array[i];
		array[i] = array[large];
		array[large] = temp;
		heapify(array, size, large);
	}
}


void heap_sort(int array[], int size)
{
	int i;
	for(i=size/2-1;i>=0;i--)
	{
		heapify(array, size, i);
	}
	for(i=size-1;i>=0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array, i, 0);
	}
}



int main()
{
	int size, i, lb, ub, mid, choice=1, task;
	int array[size];
	lb = array[0];
	ub = array[size-1];
	mid = (lb+ub)/2;
	printf("Enter the size of the array:\n");
	scanf("%d", &size);
	printf("Enter %d numbers:\n", size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("\nThe unsorted array is\n");
	for(i=0; i<size; i++)
	{
		printf("%d ", array[i]);
	}
	while(choice == 1)
	{
		printf("Enter the sorting you want to perfrom\n1 for Insertion sort\n2 for Merge Sort\n3 for Quick Sort\n4 for Bubble Sort\n5 for Bucket Sort\n6 for Radix Sort\n7 for Shell Sort\n8 for Selection Sort\n9 for Heap Sort\n");
		scanf("%d", &task);
		switch(task)
		{
			case 1:
				{
					insertion_sort(array, size);
					break;
				}
			case 2:
				{
					merge_sort(array, lb, ub);
					break;
				}
			case 3:
				{
					quick_sort(array, lb, ub);
					break;
				}
			case 4:
				{
					bubble_sort(array, size);
					break;
				}
			case 5:
				{
					bucket_sort(array, size);
					break;
				}
			case 6:
				{
					radix_sort(array, size);
					break;
				}
			case 7:
				{
					shell_sort(array, size);
					break;
				}
			case 8:
				{
					selection_sort(array, size);
					break;
				}
			case 9:
				{
					heap_sort(array, size);
					break;
				}
			default:
				{
					printf("\nEnter Valid Number\n");
				}
		}
		printf("\nDo you want to perform any more task?\nEnter 1 for YES\n0 for NO\n");
		scanf("%d", &choice);
	}

	printf("\nThe Sorted Array is\n");
	for(i=0; i<size; i++)
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}
