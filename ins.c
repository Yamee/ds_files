#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int data;
	struct node*next;
	} *head, *temp, *newnode;
int count, pos, i=1;
		
void insbeg()
{	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion:");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
}

void insend()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion:");
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
	printf("enter position:");
	scanf("%d", &pos);
	if(pos>count)
	{
		printf("invalid");
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
	}
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion:");
	scanf("%d", &newnode->data);
	temp->next = newnode;
	
		
}

void delbeg()
{
	
	if(head==0)
	{
		printf("list is empty");
	}	
	else
	{
		head=head->next;
		free(temp);
		temp=head;	
	}
}

void delend()
{
	
}

void delpos()
{
	
}

int main()
{
	void insbeg();
	void insend();
	void inspos();
	void delbeg();
	void delend();
	void delpos();
	int choice=1;	
	head=0;
	
	while(choice==1)
	{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data:");
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
	scanf("%d", &choice);
	}

	/*int sc;
	printf("enter sc (1, 2):");
	scanf("%d", &sc);
	switch(sc)
	{
		case '1':
			insbeg();
			break;
			
		case '2':
			insend();
			break;
		
		default:
			printf("invalid");	
	}*/
	
//insbeg();
//insend();
//inspos();
delbeg();
//delend();
//delpos();

	temp=head;
	while(temp!=0)
	{	
		count++;
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\nlength is %d", count);

}
