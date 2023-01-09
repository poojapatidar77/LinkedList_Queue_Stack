//circular singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *end=NULL;
void insertAtB(int);
void insertAtE(int);
void deleteAtB();
void deleteAtE();
void showall();
void display(int);
void main()
{
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
	insertAtE(50);
    //display(30);
	 showall();
     printf("\n...................\n");
	 //deleteAtB();
	 deleteAtE();
	 showall();
}
struct node *cn(int x)
{
	struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
	return temp;
}
void insertAtB(int x)
{
	struct node *temp=cn(x);
	if(start==NULL)start=end=temp->next=temp;
	else

		temp->next=start;
		start=end->next=temp;	
}
void showall()
{
	struct node *temp=start;
	do{
		printf("%d\n",temp->data);
         temp=temp->next;
	}while(temp!=start);
}
void display(int x)
{
	struct node *temp=start;
	while(temp->data!=x)
	{
		temp=temp->next;
	}
	do{
		printf("%d\n",temp->data);
		temp=temp->next;
	}while(temp->data!=x);
}
void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct node *temp=cn(x);
	temp->next=start;
	end->next=temp;
	end=temp;
}
void deleteAtB()
{
  if(start==NULL)
  {
	  printf("list is empty\n");
	  return;
  }
  struct node *temp=start;
  start=temp->next;
  end->next=start;
  free(temp);
}
void deleteAtE()
{
	if(start==NULL ||start==NULL)
	{
		deleteAtB();
		return;
	}
	struct node *temp=start;
	while(temp->next->next!=start)
	{
		temp=temp->next;
		
	}
	free(temp->next);
	temp->next=NULL;
	end=temp;	
}