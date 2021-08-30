#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define size 10
int q[size];
int rear = -1, front = -1;

void insert_q()
{
	int item, choice = 1;
	
	if(rear == size - 1)
		{
			printf("Overflow");
		}
		else
			{
				while(choice == 1)
				
				{
					if(front == -1)
						{
						
							front = 0;
							printf("\nAn Empty Queue has been created\n");
						}
					else
						{
							printf("\nEnter the item:\n");
							scanf("%d", &item);
							rear = rear + 1;
							q[rear] = item;
						}	
					printf("\nDo you want to enter more data:\nEnter 1 for YES and 0 for No\n");
					scanf("%d", &choice);
				}
				
			}
}



void delete_q()
{
	int choice = 1;
		
	while(choice == 1)
		{
			if(front == -1 || front > rear)
				{
					printf("\nUnderflow\n");
				}						
			else if(front == rear)
				{	
					printf("\nElement going to be deleted is { %d }\n", q[front]);
					front = rear = -1;
				}
			else
				{				
					printf("\nElement going to be deleted is { %d }\n", q[front]);
					front = front + 1;
				}
			printf("\nDo you want to delete more data:\nEnter 1 for YES and 0 for No\n");
			scanf("%d", &choice);
		}
}



void display_q()
{
	int i;
	if(front == -1)
		{
			printf("\nQueue is Empty\n");
		}
	else
		{
			printf("\nQueue is \n");
			for(i = front; i <= rear; i++)
				{
					printf("%d ", q[i]);
				}
			printf("\n\n");
		}
}


int main()
{
	int choice = 1, task;
	printf("\nImplementation in Queue using Array\n");
	while(choice == 1)
		{
			printf("\nEnter the task you want to perform\n2 for Insertion \n3 for Deletion\n4 for Display\n");
			scanf("%d", &task);
			switch(task)
				{
					case 2:
					insert_q(q);
					break;
					
					case 3:
					delete_q(q);
					break;
					
					case 4:
					display_q(q);
					break;
					
					default:
					printf("\nWrong Choice");
				}
			printf("\nDo you want to perform more task:\nEnter 1 for YES and 0 for No\n");
			scanf("%d", &choice);
		}
	printf("\nExiting Program\n");
	exit(0);
	return 0;
}
