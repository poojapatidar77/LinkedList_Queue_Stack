#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int queue[capacity];
int f=-1;
int r=-1;
void enqueue(int);
int dequeue();
bool  isfull();
bool isempty();
void showall();
void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50); 
	showall();
	printf("\n.................\n");
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("\n.................\n");
    showall();
}
void enqueue(int v)
{
   if(f==-1)
   {
	   f++;
    queue[++r]=v;
   }
   else if((r+1)%capacity==f)
   {
	   printf("queue is full\n");
   }
   else
   {
	   r=(r+1)%capacity;
	   queue[r]=v;
   }
}
int dequeue()
{
	if(f==-1)
	{
		printf("queue is empty\n");
		return -1;
	}
	else if(f==r)
	{ 
       int x=f;
	     f=-1;
		return queue[x];
	 }
	else
	{
	return queue[f++];
    }
}
void showall()
{
	if(f==-1)
	{
		printf("queue is empty\n");
		return;
	}
	else
	{
	int i=f;
	// for(i=f;i!=r;i=(i+1)%capacity)
	// {
		// printf("%d\n",queue[i]);
	// }
		// printf("%d\n",queue[i]);
	do
	{
		 printf("%d\n",queue[i]);
		    i=(i+1)%capacity;
	}while(i!=f);
	}
}