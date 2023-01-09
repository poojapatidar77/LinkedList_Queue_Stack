#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rare=NULL;
void enqueueAtE(int );
void dequeueAtB();
void enqueueAtB(int );
void dequeueAtE();
void showall();
void main()
{
	//enqueueAtE(10);
	//enqueueAtE(20);
	//enqueueAtE(30);
	//enqueueAtE(40);
    //showall();
	printf("\n...................\n");
	enqueueAtB(10);
	enqueueAtB(20);
	enqueueAtB(30);
	enqueueAtB(40);
    showall();
	printf("\n...................\n");
	//dequeueAtB();
	//dequeueAtB();
	//dequeueAtB();
	//dequeueAtB();
	dequeueAtE();
	dequeueAtE();
	dequeueAtE();
    dequeueAtE();
	
	showall();
 
}
struct node *cn(int x)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	return temp;
}
void enqueueAtE(int x)
{
	struct node *temp=cn(x);
	 temp->next=NULL;

	if(front==NULL)
	{
 		front=rare=temp;
 	}
	else
	{
		rare->next=temp;
		rare=temp;
	}
}
void dequeueAtB()
{
	struct node *temp=front;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return ;
	}
	front =temp->next;
     free(temp);	
}
void dequeueAtE()
{
	struct node *temp=front;
	struct node *temp2;

  if(front ==NULL )
  {
	  printf("queue is empty\n");
	  return ;
  }
     while(temp->next!=NULL)
	 {
		 temp2=temp;
		 temp=temp->next;
	 }
	 if(front==rare)
	 {
		 front=rare=NULL;
		 return;
	 }
	 temp2->next=NULL;
	 rare=temp2;
	 free(temp);
}
void enqueueAtB(int x)
{
 	if(front==NULL)
	{
		 enqueueAtE(x);
	return ;
	}
	struct node *temp=cn(x);
	temp->next=front;
	front=temp;
}
void showall()
{
	struct node *temp=front;
	if(front==NULL )
	{
		printf("queue is empty\n");
		return ;
	}
	while(temp!=rare->next)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
