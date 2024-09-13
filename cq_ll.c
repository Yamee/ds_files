#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int data;
	struct node*next;
	}*f=0, *r=0, *temp, *newnode;

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
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter element:");
	scanf("%d", &newnode->data);
	newnode->next=0;
	if(f==0 && r==0)
	{
		f=r=newnode;
		r->next =f;
	}
	else
	{
		r->next=newnode;
		r=newnode;
		r->next=f;
	}
}

void dequeue()
{
	struct node* temp=f;
	if(f==0 && r==0)
	{
		printf("Queue Underflow\n");
	}
	else if(f == r)
	{
		f=r=0;
		printf("%d is deleted\n", temp->data);
		free(temp);
	}
	else
	{
		f=f->next;
		r->next=f;
		printf("%d is deleted\n", temp->data);
		free(temp);
	}
}

void peek()
{
	if(f==0 && r==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("Top element is %d\n", f->data);
	}
}

void display()
{
	struct node* temp=f;
	if(f==0 && r==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		while(temp->next!=f)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		printf("%d\n", r->data);
	}
}
