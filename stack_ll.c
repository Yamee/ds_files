#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*top=0, *newnode, *temp;

void main()
{
	int ch;
	do
	{
		printf("\nEnter choice \n1.push 2.pop 3.peek 4.display:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push();
				break;	
			case 2:
				pop();
				break;	
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default: printf("Invalid choice\n");
		}
	}while(ch!=0);	
}

void push()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for creation:");
	scanf("%d", &newnode->data);
	newnode->next=0;
	if(top==0)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}

void pop()
{
	temp=top;
	if(top==0)
	{
		printf("Stack Underflow");
	}
	else if(top->next==0)
	{
		top=0;
		printf("element deleted is %d", top->data);
		free(top);
	}
	else
	{
		top=top->next;
		printf("element deleted is %d\n", temp->data);
		free(temp);
	}
}

void peek()
{
	if(top==0)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("Top element is %d\n", top->data);
	}
}

void display()
{
	temp=top;
	if(top==0)
	{
		printf("Stack Underflow");
	}
	else
	{
		while(temp!=0)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
