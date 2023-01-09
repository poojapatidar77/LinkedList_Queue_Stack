//doubly circular linked list

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
void insertAtB(int );
void insertAtE(int );
void showall();
void main()
{
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
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
   if(start==NULL)temp->next=start=end=temp;
     temp->prev=end;
	 temp->next=start;
	 end->next=start->prev=temp;
      start=temp;
}
void showall()
{
struct node *temp=start;
do{
printf("%d\n",temp->data);
temp=temp->next;
}while(temp!=start);
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
   temp->prev=end;
   start->prev=end->next=temp;
    end=temp;
}