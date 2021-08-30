#include<stdio.h>
#include<malloc.h>

int main()
{	
	struct node
	{
		int info;
		struct node *link;
	};
	typedef struct node node;
	
	node *new, *start, *temp = 0;
	int choice = 1;
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
	return 0;
}
