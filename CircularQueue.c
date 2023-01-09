#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int queue[capacity];
int f=-1;
int r=-1;
void enqueue(int );
int dequeue();
int peek();
void showall();
bool isfull();
bool isempty();
void main()
{
	 enqueue(10);
	 enqueue(20);
	 enqueue(30);
	 enqueue(40);
	 enqueue(50);
	 enqueue(100);
    showall();
printf("\n............\n");
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	printf("\n............\n");
    showall();
	printf("\n............\n");
    enqueue(121);
    enqueue(122);
    enqueue(123);
    enqueue(124);
	showall();
}  
void enqueue(int x)
{
	if(f==-1)
	{
		f++;
		r++;
		queue[r]=x;
	}
	else if((r+1)%capacity==f)
	{
		printf("queue is full\n");
	   return ;
	}
	else
	{
		r=(r+1)%capacity;
		queue[r]=x;
	}
}
int dequeue()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return -1;
	}
	return queue[f++];
}
int peek()
{
	if(isempty())
	{
		printf("queue is empty\n");
	}
	else return queue[f];
}
bool isempty()
{
	if(f==-1)return true;
	else return false;
}
void showall()
{
	if(isempty())
	{
		printf("list is empty");
		return;
	}
	int i;
	 
	for(i=f;i!=r;i=(i+1)%capacity)
		printf("%d\n",queue[i]);
	 	
		printf("%d\n",queue[i]);

	

	
}