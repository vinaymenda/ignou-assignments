/*

Write an algorithm that accepts a Tree as input and converts it into a Binary Tree and then prints 
all the leaf nodes that are part of both Tree and Binary Tree

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *left;
	struct node *right;
};


struct node* insert(struct node *curr, struct node *newnode)
{
	if(curr == NULL)
	{
		curr = newnode;
	}
	else
	{
		if(newnode -> value <= curr -> value)
		{
			if(curr -> left == NULL)
			{		
				curr -> left = newnode;
			}
			else
			{
				insert(curr -> left, newnode);
			}
		}
		else
		{
			if(curr -> right == NULL)
			{
				curr -> right = newnode;
			}
			else
			{
				insert(curr -> right, newnode);
			}
		}	
	}
	return curr;
}

void inorder(struct node *curr)
{
	if(curr -> left != NULL)
	{
		inorder(curr -> left);
	}
	printf("%d  ", curr -> value);
	if(curr -> right != NULL) 
	{
		inorder(curr -> right);	
	}
}

void preorder(struct node *curr)
{
	printf("%d  ", curr -> value);
	if(curr -> left != NULL)
	{
		preorder(curr -> left);
	}
	if(curr -> right != NULL)
	{
		preorder(curr -> right);
	}
}

void postorder(struct node *curr)
{	
	if(curr -> left != NULL)
	{
		postorder(curr -> left);
	}
	if(curr -> right != NULL)
	{
		postorder(curr -> right);
	}
	printf("%d  ", curr -> value);
}

void printleaves(struct node *curr)
{
	if(curr == NULL)
	{
		return;
	}
	if(curr -> left == NULL && curr -> right == NULL)
	{
		printf("%d  ", curr-> value);
	}
	printleaves(curr -> left);
	printleaves(curr -> right);
}

int main()
{
	int numberOfnodes; int value;
	printf("Enter number of nodes: ");
	scanf("%d", &numberOfnodes);
	
	struct node *root = NULL;
	while(numberOfnodes!=0)
	{
		printf("Enter node value: ");
		scanf("%d", &value);
		struct node *newnode =  (struct node*)malloc(sizeof(struct node));
		if(newnode == NULL)
		{
			printf("Cannot allocate\n");
			exit(0);
		}
		newnode->value = value;
		newnode -> left = NULL; newnode -> right = NULL;
		
		root = insert(root, newnode);		
		numberOfnodes--;
	}
	
	printf("\n\n");
	printf("Binary tree is as follows: ");
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nInorder: ");
	inorder(root);
	
	printf("\n\n");
	printf("Leaf nodes: ");
	printleaves(root);
	return 0;
}


