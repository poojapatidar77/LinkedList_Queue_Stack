#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define capacity 50
int top=-1;
char stack[capacity];
void push(char);
char peek();
char pop();
bool isEmpty();
char pr(char);
void main()
{
	 char input[capacity];
	 char output[capacity]="";
	printf("enter the expression\n");
	scanf("%s",input);
   int m,t,n,i=0,k=0,c=0;
   for(m=0;input[m]!='\0';m++)c++;
 	int count=0;
	for(m=1,n=c-2;m<n;)
	{
		 
		t=input[m];
		input[m]=input[n];
		input[n]=t;
		m++;n--;
	}
	for(m=1;m<=c-2;m++)
	{
 if(input[m]=='(')
		{
			input[m]=')';	
 	 continue; 	
	}		 
		if(input[m]==')')
		{
		input[m]='(';
  		}	
	}
	printf("%s\n",input);
while(input[i]!='\0') 
 {
		if(input[i]=='(')
		{
			push(input[i]);
		}
		else 
		{
			if((input[i]>='A'&& input[i]<='Z'))
			{
				output[k++]=input[i];
			}
			else if(input[i]==')')
			{
				while(peek()!='(')
				{
					output[k++]=pop();
				}
				pop();
			}
			else{
				while( pr(peek())>= pr(input[i]))
				{
				  output[k++] =	pop();
				}
              push(input[i]);
			}
		}
		i++;
	}
       for(i=0;output[i]!='\0';i++)count++;
	   printf("count =%d\n",count);
	for(i=0,k=count-1;i<k;i++,k--)
	{
		t=output[i];
		output[i]=output[k];
		output[k]=t;
	}
      printf("%s\n",output);	
}

void push(char c)
{
	if(top==capacity-1)
	{
		printf("stack is full\n");
		exit(0);
	}
	stack[++top]=c;
}
char peek()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
		exit(0);
	}
	return stack[top];
}
char pop()
{
	if(isEmpty())
	{
		printf("stack is empty\n");
		exit(0);
	}
	return stack[top--];
}
bool isEmpty()
{
	if(top==-1)return true;
	else return false;
}
char pr(char x)
{
	switch(x)
	{
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
		case '^':return 4;
		
	}
}