#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node node;

node *start;

node *sort_insert()
{
	node *new;
	int choice = 1;
	while(choice == 1)
	{	
		new = (node*)malloc(sizeof(node));
		printf("\n\nEnter the data to be enterd:");
		scanf("%d", &new->info);
		new->link = NULL;
		
		if(start == NULL)
		{
			start = new;
		}
		else if(start->link == NULL && start->info <= new->info)
		{
			start->link = new;
		}
		else if(new->info < start->info)
		{
			new->link = start;
			start = new;
		}
		else
		{
			node *ptr, *prev;
			ptr = start->link;
			prev = start;
			while(ptr->info < new->info && ptr->link != NULL)
			{
				prev = ptr;
				ptr = ptr->link;
			}
			if(ptr->link == NULL && ptr->info < new->info)
			{
				ptr->link = new;
			}
			else
			{
				prev->link = new;
				new->link = ptr;
			}
		}
		
		printf("\n\nDo you want to enter more nodes:\n");
		printf("Enter 1 for YES and 0 for NO\n");
		scanf("%d",&choice);
	}
	return start;
}


void display_list()
{
	node *ptr;
	ptr = start;
	if(start == NULL)
	{
		printf("The linked list is empty");
	}
	else
	{
		printf("\nThe Linked list is\n\n");
		while(ptr->link != NULL)
		{
			printf("%d ", ptr->info);
			ptr= ptr->link;
		}
		printf("%d ", ptr->info);
	}
}



void deletion(node *loc, node *locp, node *start)
{
	if(loc == NULL)
	{
		printf("\nThe list is empty\n");
	}
	else if(locp == NULL)
	{
		start = start->link;
		free(loc);
	}
	else
	{
		locp->link = loc->link;
		free(loc);
	}
	
	
}



void search_list()
{
	int item;
	node *loc, *locp;
	
	printf("\nEnter the value you want to delete in the list:\n");
	scanf("%d", &item);
	
	
	
	if(start == NULL)
	{
		loc = locp = NULL;
		printf("\nThe list is empty\n");
	}
	else if(item == start->info)
	{
		loc = start;
		locp = NULL;
	}
	else
	{
		locp = start;
		loc = start->link;
		while(loc->link != NULL)
		{
			if(item == loc->info)
				{
					deletion(loc, locp, start);
				}
			if(item < loc->info)
			{	
				locp = loc = NULL;
				deletion(loc, locp, start);
			}
			locp = loc;
			loc = loc->link;
		}
		locp = NULL;
	}
	
}



int main()
{

	node *list;
	int operation, choice=1;
	
	list = (node*)malloc(sizeof(node));
	list = NULL;
	
	display_list();
	
	while(choice == 1)
	{
		printf("\nEnter the operation you want to perform on the Linked list:\n");
		printf("Enter \n2 for Inserting\n3 for Deleting\n4 for Displaying\n");
		scanf("%d", &operation);
		
		switch(operation)
		{
			case 2: list = sort_insert();
			break;
			case 3: search_list(list);
			break;
			break;
			case 4: display_list(list);
			break;
		}
		printf("\n\nDo you want to perform more operations:\n");
		printf("Enter 1 for YES and 0 for NO\n");
		scanf("%d",&choice);
		
	}
	printf("\nExiting Program");
	printf("\n\n");
	return 0;	
}
