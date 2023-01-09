//double ended queue using array

#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int queue[capacity];
int f=-1;
int r=-1;
void enqueueAtB(int);
void enqueueAtE(int );
int dequeueAtB();
int  dequeueAtE();
void showall();
void main()
{
enqueueAtE(10);
enqueueAtE(20);
enqueueAtE(30);
enqueueAtE(40);

//enqueueAtB(10);
//enqueueAtB(20);
//enqueueAtB(30);
//enqueueAtB(40);
//enqueueAtB(50);
//enqueueAtB(60);

showall();
printf("\n.............\n");
printf("%d\n",dequeueAtE());
printf("\n.............\n");
showall();
printf("\n.............\n");

enqueueAtE(100);
showall();
}
void enqueueAtB(int x)
{
	if(f==-1)
	{
	  f++;
	  r++;
	  queue[r]=x;
	}
	else if(r==capacity-1)
	{
		printf("list is full\n");
	}
	else
	{
	  int i;
	  for(i=r;i>=f;i--)
	  {
		  queue[i+1]=queue[i];
       //  printf("%d\n",queue[i]);
	  }
	  r++;
	  queue[f]=x;
	}
	
}
int dequeueAtE()
{
	if(f==-1)
	{
		printf("queue is empty\n");
	}
    else 	return queue[r--];
}
int dequeueAtB()
{
	if(f==-1)
	{
		printf("queue is empty\n");
	}
    else 	return queue[f++];
}

void enqueueAtE(int x)
{
	if(f==-1)
	{
		f++;
		r++;
		queue[r]=x;
	}
	else if(r==capacity-1)
	{
		printf("queue is full\n");
	}
	else
	{
		 queue[++r]=x;
	}
}
void showall()
{
	if(f==-1)
	{
     printf("queue is empty\n");
	 return ;
	}
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\n",queue[i]);
	}
 	
	
}






