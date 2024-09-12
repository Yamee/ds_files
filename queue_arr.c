#include<stdio.h>
#include<stdlib.h>
#define N 10
int q[N];
int f=-1;
int r=-1;

void main()
{
	int ch;
	do
	{
		printf("\nEnter choice \n1.ENQUEUE 2.DEQUEUE 3.PEEK 4.DISPLAY:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;	
			case 2:
				dequeue();
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

void enqueue()
{
	int x;
	printf("Enter element:");
	scanf("%d", &x);
	if(r==N-1)
	{
		printf("Queue Overflow\n");
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		q[r]=x;
	}
	else
	{
		r++;
		q[r]=x;
	}
}

void dequeue()
{
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else if(f==r)
	{
		printf("Deleted element is %d", q[f]);
		printf("\n");
		f=r=-1;
	}
	else
	{
		printf("Deleted element is %d", q[f]);
		printf("\n");
		f++;
	}
}

void peek()
{
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("Top element is %d\n", q[f]);
	}
}

void display()
{
	int i=f;
	if(f==-1 && r==-1)
	{
		printf("Queue Underflow\n");
	}
	else if(f==r);
	{
		for(i=f; i<=r; i++)
		{
			printf("%d\t", q[i]);
			//printf("\n");
		}
	}
}
