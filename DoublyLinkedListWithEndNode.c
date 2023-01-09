 //doubly linked list with end node
 
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
void insertAtE(int);
void deleteAtB();
void deleteAtE();
void showall();
void rev();
void main()
{
	insertAtE(10);
	insertAtE(20);
	insertAtE(30);
	insertAtE(40);
	insertAtE(50);
    showall();
	printf("\n..........................\n");
	rev();
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
	temp->prev=NULL;
	temp->next=start;
	if(start!=NULL)start->prev=temp;
	else end =temp;
	start=temp;
	 
}
void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct node *temp=cn(x);
	temp->next=NULL;
	end->next=temp;
	temp->prev=end;
	end=temp;
		
}
void rev()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp=end;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
}
void showall()
{
	struct node *temp=start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}