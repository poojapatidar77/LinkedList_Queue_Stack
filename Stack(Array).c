//stack usimg array

#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int x[capacity];
int top=-1;
void push(int v);
int pop();
int peek();
bool isempty();
bool isfull();
void main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	printf("%d\n",peek());
	printf("\n......................\n");
	printf("%d\n",pop());
	printf("\n......................\n");
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
	printf("\n......................\n");
	printf("%d\n",pop());
	printf("\n......................\n");
}
void push(int v)
{
	if(isfull())
	{
		printf("stack is full\n");
		return ;
	}
	x[++top]=v;
}
bool isempty()
{
	if(top==-1)return true;
	else return false;
}
bool isfull()
{
	if(top==capacity-1)return true;
	else return false;
}
int peek()
{
	if(isempty())
	{
	  printf("stack is empty\n");
	  return -1;
	}
	return x[top];
}
int pop()
{
	if(isempty())
	{
	  printf("stack is empty\n");
	  return -1;
	}
	return x[top--];
}
