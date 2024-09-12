#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;


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
	int x;
	printf("Enter element:");
	scanf("%d", &x);
	if(top==N-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("Deleted element is %d\n", stack[top]);
		top--;
	}
}

void peek()
{
	if(top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("Top element is %d\n", stack[top]);
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		for(i=top; i>=0; i--)
		{
			printf("%d\t", stack[i]);
		}
		printf("\n");
	}
}
