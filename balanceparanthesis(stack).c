//balance paranthesis

#include<stdio.h>
#include<stdbool.h>
#define capacity 20
int top=-1;
int a[capacity];
void push(char );
int peek();
int pop();
bool isEmpty();
void main()
{
char data[20];
printf("enter expression\n");
scanf("%s",data);
int i=0;
while(data[i]!='\0')
{
	if(data[i]=='{'||data[i]=='('||data[i]=='[')
		{
			push(data[i]);
		}
	else if(data[i]=='}'||data[i]==')'||data[i]==']')
	{
	  if(top==-1)
	  {
		  top=1;
		  break;
	  }
	if(data[i]=='}')
	{
		if(peek()=='{')
			{
				pop();
			}
			else break;
	}
	if(data[i]==']')
	{
		if(peek()=='[')
			{
				pop();
			}
			else break;
	}
	if(data[i]==')')
	{
		if(peek()=='(')
			{
				pop();
			}
			else break;
	}
	}
	i++;
}
if(top==-1)
{
	printf("correct expression\n");
}
else printf("in-correct expression\n");
}
bool isEmpty()
{
	if(top==-1)return true;
	else return false;
}
void push(char v)
{
	if(top<=capacity-1)
	a[++top]=v;
else printf("stack is full\n");
}
int pop()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
		return -1;
	}
	return a[top--];
}
int peek()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
        return -1;
	}
	return a[top];
	
}