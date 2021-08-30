#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node node;

node *front = NULL, *rear = NULL;


void insert_q()
{
	node *new;
	int item, choice = 1;
	
	
	while(choice == 1)
	{
		new = (node*)malloc(sizeof(node));
		printf("\nEnter the data:\n");
		scanf("%d", &new->info);
		new->link == NULL;
		if((front == NULL)&&(rear == NULL))
			{
				front = new;
				rear = new;
				rear->link = front;
			}
		else
			{
				rear->link = new;
				rear = new;
				rear->link = front;
			}
		printf("Do you want to enter more data:\nEnter 1 for YES and 0 for NO\n");
		scanf("%d", &choice);
	}
	
}


void delete_q()
{
	int choice = 1;
	node *temp = front;
	while(choice == 1)
	{
		if((front == NULL) && (rear == NULL))
		  	{
				printf("\nUNDERFLOW\n");
			}
		else if(front == rear)
			{
				front = rear = NULL;
				free(temp);
			}
		else
			{
				front = front->link;
				rear->link = front;
				free(temp);
			}
		printf("Do you want to delete more data:\nEnter 1 for YES and 0 for NO\n");
		scanf("%d", &choice);
	}	
}


void display_q()
{
	node *ptr;
	ptr = front;
	if((front == NULL) && (rear = NULL))
		{
			printf("\nThe list is empty\n");
		}
	else
		{
			printf("\nThe Queue is:\n");
			do{
					printf("%d ", ptr->info);
					ptr = ptr->link;
			}while(ptr != front);
			
		}
}


int main()
{
	int choice = 1, task;
	node *list;
	
	
	list = (node*)malloc(sizeof(node));
	list = NULL;
	printf("\nImplementation in Queue using Linked List\n");
	while(choice == 1)
		{
			printf("\nEnter the task you want to perform\n2 for Insertion \n3 for Deletion\n4 for Display\n");
			scanf("%d", &task);
			switch(task)
				{
					case 2:
					insert_q(list);
					break;
					
					case 3:
					delete_q(list);
					break;
					
					case 4:
					display_q(list);
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
