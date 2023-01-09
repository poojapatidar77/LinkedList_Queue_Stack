//check list is palindrome or not

#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *next;
};
struct node *start=NULL;
void insertAtB(char);
int countnode();
void showall();
int check();
void main()
{
	int i,j,s=0,c;
	insertAtB('r');
	insertAtB('a');
	insertAtB('b');
	insertAtB('b');
	insertAtB('s');
	insertAtB('r');

    printf("%d\n",countnode());	
	showall();
	int count=countnode();
	for(i=1,j=count;i<j;i++,j--)
	{
		if(check(i,j))s++; 
			else break;
	}
	if(count%2==0)c=count/2;
	else c=count/2;
	if(s==c)
	{
      printf("list is palindrome");
	}
	else printf("list is not palindrome\n");
	
}
int check(int s,int e)
{
	struct node *temp=start;
	struct node *temp2=start;
	int i,j;
	for(i=1;i<s;i++)
	{
		temp=temp->next;
	}
	for(i=1;i<e;i++)
	{
		temp2=temp2->next;
	}
	if(temp->data==temp2->data)return 1;
	else return 0;
}
int countnode()
{
	int c=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

void insertAtB(char c)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=c;
	temp->next=start;
	start=temp;
}
void showall()
{
	struct node *temp=start;
	while(temp!=NULL)
	{
		printf("%c\n",temp->data);
		temp=temp->next;
	}
}


