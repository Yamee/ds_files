#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*head, *tail, *newnode, *nextnode, *temp;

int i=1, pos, ch=1, count=0;

void create()
{
	head=0;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data:");
		scanf("%d", &newnode->data);
		newnode->next=0;
		
		if(head==0)
		{
			head=tail=newnode;
			tail->next=head;
		}
		
		else
		{
			tail->next=newnode;
			tail=newnode;
			tail->next=head;
		}
		printf("Do you want to continue(yes-1/no-0)?");
		scanf("%d", &ch);
	}
	display();
}

void insbeg()
{
	//head=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d", &newnode->data);
	newnode->next=head;
	head = newnode;
	
	if(tail==0)
	{
		tail=newnode;
		tail->next=newnode;
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
	}
	display();
}

void insend()
{
	temp=tail->next;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d", &newnode->data);
	newnode->next=0;	
	
	if(tail==0)
	{
		tail=newnode;
		tail->next=newnode;
	}
	else
	{
		while(temp->next!=tail->next)
		{
			temp=temp->next;
		}
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	display();
}

void inspos()
{
	printf("Enter postion for insertion:");
	scanf("%d", &pos);
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d", &newnode->data);
	newnode->next=0;
	if(pos==1)
	{
		insbeg();
	}
	else if(pos==count)
	{
		insend();
	}
	else if(pos<1 || pos>count)
	{
		printf("Invalid Position.");
	}
	else
	{
		temp=tail->next;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	display();
}

void delbeg()
{
	temp=tail->next;
	if(head==0)
	{
		printf("Empty list");
	}
	else if(tail->next==temp->next)
	{
		tail=0;
		free(temp);
	}
	else
	{
		head=head->next;
		tail->next=temp->next;
		free(temp);
	}
	display();
}

void delend()
{
	temp=tail->next;
	if(tail==0)
	{
		printf("Empty");
	}
	else if(temp->next==tail->next)
	{
		tail=0;
		free(temp);
	}
	else
	{
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		nextnode=temp->next;
		temp->next=tail->next;
		tail=temp;
		free(nextnode);
	}
	display();
}

void delpos()
{
	temp=tail->next;
	printf("Enter postion for deletion:");
	scanf("%d", &pos);
	if(pos==1)
	{
		delbeg();
	}
	else if(pos==count)
	{
		delend();
	}
	else if(pos<1 || pos>count)
	{
		printf("Invalid Position.");
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
	display();
}

void display()
{
	if(head==0)
	{
		printf("Linked list is empty\n");
	}
	else{
		temp=head;
		while(temp->next!=tail->next)
		{
			count++;
			printf("%d\t", temp->data);
			temp= temp->next;
		}
		printf("%d\n", tail->data);
	}	//printf("Length is %d\n", count+1);
}

int main()
{
	int choice;
	do
	{
		printf("\nenter choice:\n1- create(at start)\n2- insbeg\n3- insend\n4- inspos\n5- delbeg\n6- delend\n7- delpos\n8- display");
		printf("\n(1, 2, 3, 4, 5, 6, 7, 8):");
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
				display();
				break;
				
			default:
				printf("invalid choice!\n");		
		}
	}while(choice!=0);

	//function defination
	void create();
	void insbeg();
	void insend();
	void delbeg();
	void delend();
	void delpos();
	void display();
	
}
