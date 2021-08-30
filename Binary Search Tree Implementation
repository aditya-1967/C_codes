#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *right_child;
	struct node *left_child;
};

typedef struct node tree;


tree *search(tree *root, int x) //Searching in BST
{
	if(root == NULL || root->info == x)
		{
			return root;
		}
	else if(x > root->info)
		{
			return search(root->right_child, x);
		}
	else
		{
			return search(root->left_child, x);
		}
}


tree *new_node(int x) //Creating new node
{
	tree *new;
	new = (tree*)malloc(sizeof(tree));
	new->info = x;
	new->left_child = new->right_child = NULL;
	return new;
}


tree *insert(tree *root, int x) //Insertion
{
	if(root == NULL)
		{
			return new_node(x);	
		}
	else if(x > root->info)
		{
			root->right_child = insert(root->right_child, x);
		}
	else
		{
			root->left_child = insert(root->left_child, x);
		}
	return root;
}


tree *find_min(tree *root)
{
	if(root == NULL)
		{
			return NULL;
		}
	else if(root->right_child != NULL)
		{
			return find_min(root->left_child);
		}
	return root;
}


tree *delete(tree *root, int x)
{
	if(root == NULL)
		{
			return NULL;
		}
	else if(x > root->info)
		{
			root->right_child = delete(root->right_child, x);
		}
	else if(x < root->info)
		{
			root->left_child = delete(root->left_child, x);
		}
	else
		{
			if(root->left_child == NULL && root->right_child == NULL) //No child
				{
					free(root);
					return NULL;
				}
			else if(root->left_child == NULL || root->right_child == NULL) //One Child
				{
					tree *temp;
					if(root->left_child == NULL)
						{
							temp = root->right_child;
						}
					else
						{
							temp = root->left_child;
						}
					free(root);
					return temp;
				}
			else //Twp Children
				{
					tree *temp = find_min(root->right_child);
					root->info = temp->info;
					root->right_child = delete(root->right_child, temp->info);
				}
			return root; 
		}
}


void inorder(tree *root)
{
	if(root != NULL)
		{
			inorder(root->left_child);
			printf("%d ", root->info);
			inorder(root->right_child);
		}
}


int main()
{
	tree *root;
	int x, choice=1, info;
	printf("Enter the root node:\n");
	scanf("%d", &x);
    root = new_node(x);
    while(choice == 1)
    {
    	printf("\nEnter the root info:\n");
    	scanf("%d", &info);
    	insert(root, info);
    	printf("\nDo you want to enter more nodes:\nEnter 1 for YES and 0 for NO\n");
    	scanf("%d", &choice);
    }
    inorder(root);
    choice = 1;
    while(choice == 1)
    {
    	printf("\nEnter the root info you want to delete:\n");
    	scanf("%d", &info);
    	delete(root, info);
    	printf("\nDo you want to delete more nodes:\nEnter 1 for YES and 0 for NO\n");
    	scanf("%d", &choice);
    }
    /*
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
*/
    inorder(root);
    printf("\n");
    
    return 0;
}
