#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main()
{	
	struct node
	{
		int info;
		struct node *link;
	};
	typedef struct node node;
	
	node *new, *start, *temp = 0, *ptr, *pre;
	int choice = 1, delchoice;
	start = 0;
	
	while(choice == 1)
	{
		new = (node*)malloc(sizeof(node));
		printf("Enter the data to be enterd:");
		scanf("%d", &new->info);
		if(start != 0)
		{
			temp->link = new;
			temp = new;
		}
		else
		{
			start = temp = new;
		}
		fflush(stdin);
		printf("\n\nDo you want to enter more nodes:\n");
		printf("Enter 1 for Yes and 0 for No.\n");
		scanf("%d", &choice);
	}
	
	temp->link = 0;
	temp = start;
	printf("\n\nThe linked list is:\n");
	while(temp != NULL)
	{
		printf("%d ", temp->info);
		temp = temp-> link;
	}
	printf("\n\n");
	
	printf("Do you want to Delete a node from the last? (enter 0 for no and 1 for yes):");
	scanf("%d", &delchoice);
	
	printf("\n\n");
	if(delchoice == 1)
	{
		printf("Now deleting one node from the last");
		choice = 1;

		while(choice == 1)
		{
			if(start == NULL)
			{
				printf("Underflow");
			}
			else if(start->link == NULL)
			{
				start = NULL;
				free(start);
			}
			else
			{
				pre = start;
				ptr = start->link;
				while(ptr->link != NULL)
				{
					pre = ptr;
					ptr = ptr->link;
				}
				pre->link = NULL;
				free(ptr);
				printf("\nDeleted one node from the last\n");
			}
			printf("\n\nDo you want to delete more nodes:\n");
			printf("Enter 1 for Yes and 0 for No.\n");
			scanf("%d", &choice);	
		}	
	
		ptr->link = 0;
		ptr = start;
		printf("\n\nThe linked list is:\n");
		while(ptr != NULL)
		{
			printf("%d ", ptr->info);
			ptr = ptr-> link;
		}
	}
	else 
	{
		printf("\nExiting Program\n");
		exit(0);
	}
	
	printf("\n\n");
	return 0;
}
