#include<stdio.h>
#include<stdbool.h>
#define capacity 15
char stack[capacity];
int top=-1;
void push(char);
char pop();
char peek();
bool isempty();
bool isfull();
int check(char);
void main()
{ 
char data[20];
char output[20]=" ";
printf("enter the expression\n");
scanf("%s",data);
int i=0,j=0;
while(data[i]!='\0')
{
	if(data[i]=='(')
	{
		push(data[i]);
	}
	else
	{
	if(data[i]>='A'&&data[i]<='Z')
	{
		output[j++]=data[i];
	}
	else if(data[i]==')')
	{
		while(peek()!='(')
		{
			output[j++]=pop();
		}
		pop();
	}
	else
	{
		while(check(peek())>=check(data[i]))
		{
		output[j++]=pop();
	    }
		
		push(data[i]);
	}
	}
	i++;
}
printf("\n%s",output);

}
void push(char x)
{ 
	stack[++top]=x;
}
char pop()
{
	if(isempty())
	{
		printf("stack is empty\n");
	 }
	else return stack[top--];
}
char peek()
{
	if(isempty())
	{
		printf("stack is empty\n");
	 }
	else return stack[top];
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
int check(char c)
{
	switch(c)
	{
		case '(':return 1;
		
		case '+':
		case '-':return 2;
		
		case '*':
		case '/':return 3;
		
		case '^':return 4;
	}
}