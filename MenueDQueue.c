//menue driven program of queue

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define capacity 15
int queue[capacity];
void enqueue(int );
int f=-1;
int r=-1;
int dequeue();
int peek();
bool isEmpty();
bool isFull();
void showall();
void main()
{
   
      int c;
	  M:
	 printf("\n.........MENUE.........\n");
	 printf("1: enquene\n");
	 printf("2: dequene\n");
	 printf("3: peek\n");
	 printf("4: showall\n");
	 printf("5: exit\n");
	 printf("enter your choice :");
	 scanf("%d",&c);
	 if(c>=1 && c<=5)
	 {
     switch(c)
	 {
		 case 1:
		 enqueue(10);
	     enqueue(20);
	     enqueue(30);
         enqueue(40);
	     showall();
		 goto M;
		 
		 case 2:
		 printf("\n............\n");
		  printf("%d\n",dequeue());
		 showall();
		  goto M;
		  
		  case 3:
		  printf("peek=%d\n",peek());
	      goto M;
		  
		  case 4:
		  showall();
		  goto M;
		  
		  case 5:
		  exit;
		  break;
	 }
	 }
	 else{
      printf("invalid choice \n");
	 }
	
}
void enqueue(int x)
{
	 	
	if(f==-1)f++;
	queue[++r]=x;
}
int dequeue()
{
if(isEmpty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	return queue[f++];
}
int peek()
{
if(isEmpty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	return queue[f];
}
void showall()
{
	if(isEmpty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	printf("\n....................\n");
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\n",queue[i]);
	}
		printf("\n....................\n");

}
bool isEmpty()
{
	if(f==-1||f>r)return true;
	else return false;
}
bool isFull()
{
	if(r!=capacity-1)return true;
	else false;
}