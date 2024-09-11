#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int data;
	struct node*next;
	} *head, *temp, *newnode, *nextnode, *prev, *cur;

int count, pos, i=1;

void create()
{
	//char ch ='y';
	int ch=1;
	head=0;
	
	//while(ch=='y')	
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
	printf("do you want to continue(yes-1/no-0)?");
	scanf("%d", &ch);
	//scanf("%s", &ch);
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
	else
	{
		
		while(i<pos-1)
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

void reverse()
{
	prev=0;
	cur=nextnode=head;
	while(nextnode!=0)
	{
		nextnode=nextnode->next;
		cur->next=prev;
		prev=cur;
		cur=nextnode;
	}
	head=prev;
}

void display()
{
		temp=head;
		while(temp!=0)
		{	
			count++;
			temp = temp->next;
		}
		printf("\nlength is %d\n", count);
}

void main()
{
	int choice;
	do
	{
		printf("\n\nenter choice:\n1- create(at start)\n2- insbeg\n3- insend\n4- inspos\n5- delbeg\n6- delend\n7- delpos\n8- reverse\n9- display");
		printf("\n(1, 2, 3, 4, 5, 6, 7, 8, 9):");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				create();
				break;
				
			case 2:
				insbeg();
				break;
				
			case 3:
				insend();
				break;
				
			case 4:
				inspos();
				break;
				
			case 5:
				delbeg();
				break;
				
			case 6:
				delend();
				break;
				
			case 7:
				delpos();
				break;
				
			case 8:
				reverse();
				break;
				
			case 9:
				display();
				break;
				
			default:
				printf("invalid choice!\n");		
		}
		temp=head;
		while(temp!=0)
		{
			printf("%d\t", temp->data);
			temp = temp->next;
		}	
	}while(choice!=0);	
	
	//function defination
	void create();
	void insbeg();
	void insend();
	void inspos();
	void delbeg();
	void delend();
	void delpos();
	void display();
}
