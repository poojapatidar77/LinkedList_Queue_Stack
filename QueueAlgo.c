#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define capacity 5
int queue[capacity];
void enqueue(int );
int dequeue();
int f=-1;
int r=-1;
int peek();
void showall();
bool isempty();
bool isfull();
void main()
{
	int i ;
	int x[]={10,20,30,40,50};
	for(i=0;i<5;i++)
	{
	enqueue(x[i]);
	}
	showall();
	printf("\n............\n");
    printf("%d\n",dequeue());
	printf("\n............\n");
	
	showall();
   
printf("\n...........\n");   
   printf("%d\n",peek());
    
}
bool isfull()
{
	if(r==capacity-1)return true;
	else return false;
}
bool isempty()
{
	if(f==-1||f>r)return true;
	else return false;
}
void enqueue(int x)
{
	if(isfull())
	{
		printf("queue is full\n");
		return ;
	}
	if(f==-1)f++;
	queue[++r]=x;
}
int dequeue()
{
	if(isempty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	return queue[f++];
}
int peek()
{
	if(isempty())
	{
		printf("queue is empty\n");
		exit(0);
	}
	return queue[f];
}
void showall()
{
	if(isempty())
	{
		printf("list is empty\n");
		exit(0);
	}
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\n",queue[i]);
	}
}