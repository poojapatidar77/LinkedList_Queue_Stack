//circular queue using lisked list


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rare=NULL;
void enqueue(int );
void dequeue();
void showall();
void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
  showall();
  printf("\n...........\n");
  dequeue();
  //dequeue();
  //dequeue();
  //dequeue();
 // dequeue();
  //dequeue();

  showall();
  printf("\n...........\n");
  enqueue(121);
  showall();
}
void enqueue(int x)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	if(front==NULL)
	{
		rare=front=temp;
		temp->next=front;
	}
	else 
	{
		rare->next=temp;
		rare=temp;
		temp->next=front;
	
	}
}
void dequeue()
{
		struct node *temp=front;

	if(rare==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	else if(front==rare)
	{
		rare=front=NULL;
		free(temp);
	}
	else
	{
 	front=temp->next;
	rare->next=front;
	free(temp);
}
}
void showall()
{
	if(front==NULL)
	{
		printf("queue is empty\n");
		return ;
	}
	struct node *temp=front;
	do
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	while(temp!=rare->next);
}