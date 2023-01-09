#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int queue[capacity];
int f=-1;
int r=-1;
void enqueueAtE(int );
void enqueueAtB(int );
bool isempty();
bool isfull();
void showall();
void dequeueAtB();
void dequeueAtE();
void main()
{
	enqueueAtE(10);
	enqueueAtE(20);
	enqueueAtE(30);
	enqueueAtE(40);
	enqueueAtE(50);
	
	showall();
	// enqueueAtE(60);
	printf("\n........................\n");
	dequeueAtB();
	dequeueAtB();
	showall();

	 printf("\n........................\n");
     enqueueAtB(121);
	showall();
	 printf("\n........................\n");
	// dequeueAtB();
	// dequeueAtB();
	// dequeueAtB();
	// showall();
	 printf("\n........................\n");
	dequeueAtE();
	showall();
	 printf("\n........................\n");
 }
void showall()
{
	if(f==-1)
	{
		printf("queue is empty\n");
		return;
	}
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\n",queue[i]);
	}
}
void enqueueAtE(int v)
{
	if(r==capacity-1)
	{
		printf("queue is full\n");
		return;
	}
	if(f==-1)f++;
	queue[++r]=v;
} 
void dequeueAtB()
{
	if(f==-1||f>r)
	{
		printf("queue is empty\n");
		return ;
	}
	 queue[f++];
}
void dequeueAtE()
{
 if(f==-1)
 {
		printf("queue is empty\n");
     return ;	 
 }	 
 r--;
}
void enqueueAtB(int v)
{
if(f==0)
{
	printf("queue is full\n");
	return ;
}
queue[--f]=v;
}