#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int data;
	struct node*next;
	} *head, *temp, *newnode;

int count, pos, i=1;

void create()
{
	int ch=1;	
	head=0;
	
	while(ch==1)
	{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for creation:");
	scanf("%d", &newnode->data);
	newnode->next=0;
	
	if(head==0)
	{
		head=temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
	printf("do you want to continue(0,1)?");
	scanf("%d", &ch);
	}
}
		
void insbeg()
{	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion at beginnig:");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
}

void insend()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion at end:");
	scanf("%d", &newnode->data);
	temp=head;
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	temp->next = newnode;
	temp=newnode;
	newnode->next=0;
	
}

void inspos()
{
	temp=head;
	printf("enter position for insertion:");
	scanf("%d", &pos);
	if(pos==1)
	{
		insbeg();
	}
	else if(pos==count)
	{
		insend();
	}
	else if(pos<i || pos>count)
	{
		printf("Invalid position, no insertion\n");
	}
	else
	{
		
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("enter data for insertion at position:");
		scanf("%d", &newnode->data);
		newnode->next = temp->next;
		temp->next = newnode;
	}
			
}

void delbeg()
{
	
	if(head==0)
	{
		printf("list is empty");
	}	
	else
	{
		temp=head;
		head=head->next;
		free(temp);
			
	}
}

void delend()
{
	struct node*prev;
	temp=head;
	while(temp->next!=0)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	temp=prev;
}

void delpos()
{
	struct node* nextnode;
	temp=head;
	printf("enter position for deletion:");
	scanf("%d", &pos);
	if(pos==1)
	{
		delbeg();
	}
	else if(pos==count)
	{
		delend();
	}
	else
	{
	while(i<pos-1)
	{
		temp=temp->next;
		i++;	
	}	
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
	}
}

void main()
{
	int choice;
	do
	{
		printf("\nenter choice:\n1- create\n2- insbeg\n3- insend\n4- inspos\n5- delbeg\n6- delend\n7- delpos");
		printf("\n(1, 2, 3, 4, 5, 6, 7):");
		scanf("%d", &choice);
		switch(choice)
		{
			case '1':
				create();
				break;
				
			case '2':
				insbeg();
				break;
				
			case '3':
				insend();
				break;
				
			case '4':
				inspos();
				break;
				
			case '5':
				delbeg();
				break;
				
			case '6':
				delend();
				break;
				
			case '7':
				delpos();
				break;
				
			//default:
			//	printf("invalid choice!");		
		}
	}while(choice!=0);
	
	
	//display
	temp=head;
	while(temp!=0)
	{	
		count++;
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\nlength is %d", count);	

	//function defination
	void create();
	void insbeg();
	void insend();
	void inspos();
	void delbeg();
	void delend();
	void delpos();
	
	
}
