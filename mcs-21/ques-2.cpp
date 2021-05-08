/*

Is it possible to implement multiple stacks in a Queue. If Yes, (i)Is there any limit on the number 
of Stacks that can be implemented in a Queue.(ii) Implement two Stacks in a Queue

*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void push(struct node **tos, int item)
{
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	if (newnode == NULL) 
	{
        printf("Stack overflow \n");
        return;
    }
	newnode -> data = item;
	newnode -> next = *tos;
	*tos = newnode;	
}

int pop(struct node **tos)
{
	struct node *temp; 
	temp = *tos;
	if(temp == NULL)
	{
		return (NULL);
	}
	else
	{
		int data = temp -> data;
		*tos = temp -> next;
		free(temp);
		return data;
	}
}

struct queue
{
	struct node *stack1;
	struct node *stack2;
};

void enqueue(struct queue *q, int item)
{
	push(&q -> stack1, item);
}

void dequeue(struct queue *q)
{
	int data;
	if(q -> stack1 == NULL && q -> stack2 == NULL)
	{
		printf("Queue is empty. \n");
		return;
	}
	if(q -> stack2 == NULL)
	{
		while(q -> stack1 != NULL)
		{
			data = pop(&q -> stack1);
			push(&q -> stack2, data);
		}
	}
	data = pop(&q->stack2);
	printf("Item removed: %d\n", data);
}

void display(struct queue *q)
{
	struct node *stack1 = q -> stack1;
	while(stack1 != NULL)
	{
		printf("%d\n", stack1 -> data);
		stack1 =stack1 -> next;
	}
	
	struct node *stack2 = q -> stack2;
	while(stack2 != NULL)
	{
		printf("%d\n", stack2 -> data);
		stack2 =stack2 -> next;
	}
}

int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q -> stack1 = NULL; q -> stack2 = NULL;
	int choice; 
	int data;
	char ch = 'y';
	
	do 
	{
		printf("Options: \n1. Add to queue \n2. Remove from queue \n3. Display \n4. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
			printf("Enter item to be queued: ");			
			scanf("%d", &data);
			enqueue(q, data);
			break;
			
			case 2:
			dequeue(q);
			break;
			
			case 3:
			display(q);
			break;	
			
			 case 4 : 
			 exit(1);             
			
			default: 
			printf("Invalid choice!");
			break;		
		}
	}
	while(ch == 'y');	
	
	
	printf("out of main");
	return 0;
}


