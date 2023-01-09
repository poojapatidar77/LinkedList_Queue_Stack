//circular doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
struct node *end=NULL;
void insertAtB(int);
void insertAtE(int);
void deleteAtB();
void deleteAtE();
void showall();
void main()
{
	// insertAtB(10);
	// insertAtB(20);
	// insertAtB(30);
	// insertAtB(40);
	// insertAtB(50);
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
	insertAtE(50);
	showall();
	printf("\n...................\n");
	// deleteAtB();
	// deleteAtB();
	// deleteAtB();
	// deleteAtB();
	//deleteAtB();
	//deleteAtB();
	deleteAtE();
	deleteAtE();
	deleteAtE();
	deleteAtE();
	deleteAtE();
	deleteAtE();
	showall();
}
struct node *cn(int x)
{
	struct node *temp=malloc(sizeof(struct node ));
	temp->data=x;
	return temp;
}
void insertAtB(int x)
{
	struct node *temp=cn(x);
	if(start==NULL)
	{
		temp->next=temp->prev=end=start=temp;
		return ;
	}
	temp->next=start;
	temp->prev=end;
	end->next=temp;
	start->prev=temp;
	start=temp;
}
void deleteAtB()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp=start;
	if(start==end)
	{
		free(temp);
		start=end=NULL;
		return;
	}
	start=temp->next;
	start->prev=end;
	end->next=start;
	free(temp);
}
void insertAtE(int x)
 {
 	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct node *temp=cn(x);
	 
	temp->prev=end;
	temp->next=start;
    end=start->prev=end->next=temp;
}
void deleteAtE()
{
	if(start==NULL)
	{
		deleteAtB();
		return;
	}
	struct node *temp=end;
	if(start==end)
	{
		free(temp);
		start=end=NULL;
		return;
	}
	end=temp->prev;
	end->next=start;
	start->prev=end;
	free(temp);
}
void showall()
{
	if(start==NULL )
	{
		printf("list is empty\n");
		return ;
	}
	struct node *temp=start;
	do
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}while(temp!=start);
}