#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next, *prev;
}*head, *temp, *tail, *newnode, *nextnode, *cur, *prev;

int i=1, pos, count=0, ch=1;

void create()
{
	head=0;
	while(ch==1)
	{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d", &newnode->data);
	newnode->next=0;
	newnode->prev=0;
	
	if(head==0)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		newnode->prev = tail;
		tail=newnode;
		temp=newnode;
	}
	printf("do you want to continue (yes-1/no-0)?");
	scanf("%d", &ch);
	}
}

void insbeg()
{
	newnode= (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion in begining:");
	scanf("%d", &newnode->data );
	newnode->next =0;
	newnode -> prev =0;
	if(head==0)
	{
		head=tail=newnode;
	}
	else
	{
		temp=head;
		newnode->next = head;
		head= newnode;
		temp->prev = newnode;
		//temp=head; //for display
	}
}

void insend()
{
	newnode= (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion in end:");
	scanf("%d", &newnode->data );
	newnode->	next =0;
	newnode->prev= tail;
	tail->next=newnode;
	tail=newnode;
	
}

void inspos()
{
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
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data for insertion at position:");
		scanf("%d", &newnode->data );
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
}

void delbeg()
{
	temp=head;
	if(head==0)
	{
		printf("List is empty");	
	}
	else
	{
		head=head->next;
		head->prev=0;
		free(temp);
	}	
}

void delend()
{
	temp=tail;
	if(tail==0)
	{
		printf("List is empty");
	}
	else
	{
		tail=tail->prev;
		tail->next=0;
		free(temp);
	}
}

void delpos()
{
	printf("Enter positon for deletion:");
	scanf("%d", &pos);
	if(pos==1)
	{
		delbeg();
	}
	else if(pos==count)
	{
		delend();
	}
	else if(pos<1 ||pos>count)
	{
		printf("Invalid Choice");
	}
	else
	{
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;
		nextnode->next->prev=temp;
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

int main()
{				
	int choice;
	do
	{
		printf("\nenter choice:\n1- create(at start)\n2- insbeg\n3- insend\n4- inspos\n5- delbeg\n6- delend\n7- delpos\n8- reverse\n9- display");
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
		//display
		temp=head;
		while(temp!=0)
		{
			printf("%d\t", temp->data);
			temp = temp->next;
		}	
	}while(ch!=0);
	
			
	//function defination
	void create();
	void inspos();
	void insbeg();
	void insend();
	void delbeg();
	void delend();
	void delpos();
	
}

	

