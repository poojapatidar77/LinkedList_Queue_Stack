//queue linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rare =NULL;
void enqueue(int);
void dequeue();
int peek();
void showall();
void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
    showall();
	printf("\n.......\n");
	dequeue();
	dequeue();
	dequeue();
	//dequeue();
	//dequeue();

	showall();
	printf("\n.......\n");
	printf("%d\n",peek());
}
void enqueue(int x)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	if(front==NULL)
	{
		temp->next=rare;
		front=rare=temp;
	}
	temp->next=NULL;
	rare->next=temp;
	rare=temp;
}
void showall()
{
	struct node *temp=front;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void dequeue()
{
	 struct node *temp=front;

	 if(temp==NULL)
	 {
		 printf("queue is empty\n");
		 return ;
	 }
 	 front=temp->next;	 
      free(temp);   
}
int peek()
{
if(front==NULL)
{
	printf("queue is NULL\n");
	exit(0);
}	
return front->data;
}