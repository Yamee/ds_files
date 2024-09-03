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
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data for insertion:");
	scanf("%d", &newnode->data);
	newnode->next = temp->next;
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
	while(i<pos-1)
	{
		temp=temp->next;
		i++;	
	}	
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}

int main()
{
	void insbeg();
	void insend();
	void inspos();
	void delbeg();
	void delend();
	void delpos();
	int ch=1;	
	head=0;
	
	while(ch==1)
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
	scanf("%d", &ch);
	}

	int choice;
	printf("\nchoice:\n1- insbeg\n2- insend\n3- inspos\n4- delbeg\n5- delend\n6- delpos\nenter choice (1, 2, 3, 4, 5, 6):");
	scanf("%d", &choice);
	switch(choice)
	{
		case '1':
			insbeg();
			break;
			
		case '2':
			insend();
			break;
			
		case '3':
			inspos();
			break;
			
		case '4':
			delbeg();
			break;
			
		case '5':
			delend();
			break;
			
		case '6':
			delpos();
			break;
			
		/*default:
			printf("invalid choice:");*/		
	}
	

	temp=head;
	while(temp!=0)
	{	
		count++;
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\nlength is %d", count);

}
