//satck linked list

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int );
int peek();
int pop();
bool isEmpty();
struct node *cn()
{
	return malloc(sizeof(struct node ));
}
void main()
{
	push(10);
	push(20);
	push(30);
	push(40);
printf("%d\n",peek());
printf("%d\n",peek());
printf("%d\n",pop());
printf("%d\n",pop());
printf("%d\n",pop());
printf("%d\n",pop());
printf("%d\n",pop());

}
bool isEmpty()
{
	if(top==NULL)return true;
	else return false;
}
void push(int x)
{
	struct node *temp=cn();
	if(temp==NULL)
	{
		printf("stack is full\n");
		return;
	}
	temp->data=x;
	temp->next=top;
	top=temp;
	
}
int peek()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
		return -1;
	}
	return top->data;
}
int pop()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
		return -1;
	}
	struct node *temp=top;
	int x=top->data;
	top=top->next;
	free(temp);
	return x;
}