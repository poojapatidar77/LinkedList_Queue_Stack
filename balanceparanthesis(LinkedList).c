//balance parnthesis (linked list )//

#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insertAtB(char);
void  deleteAtB();
int peek();
void main()
{
	char c[100];
	printf("enter expression\n");
	scanf("%s",c);
	int i =0;
	while(c[i]!='\0')
	{
	if(c[i]=='{'||c[i]=='('||c[i]=='[')
	{
		insertAtB(c[i]);
	}
	else if(c[i]=='}'||c[i]==')'||c[i]==']')
	{
		if(start==NULL)
		{
			printf("incorrct expression\n");
			exit(0);
		}
	if(c[i]=='}' )
	{
		if(peek()=='{')
		{
		printf("%c\n",peek());
		deleteAtB();
		}
	else break;
	}
	if(c[i]==')')
	{
		if(peek()=='(')
//	printf("%c\n",peek());
		deleteAtB();
		
	else break;
	
	}
	if(c[i]==']')
	{
		if(peek()=='[')
		deleteAtB();
	
	else break;
	}
	}		
	i++;
	}

  if(start==NULL)
  {
	  printf("correct expression\n");
  }
  else{
    printf("in correct expression\n");
  }
}
void insertAtB(char x)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=start;
	start=temp;
}
int peek()
{
	//struct node *temp=start;
	return start->data;
}
void  deleteAtB()
{
	struct node *temp=start;
	//char x=temp->data;
	start=temp->next;
    free(temp);
	//return x;
}