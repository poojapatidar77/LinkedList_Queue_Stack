//doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
void insertAtB(int);
void insertAtE(int );
void deleteAtB();
void deleteAtE();
int  countnode();
void insertAtsp(int ,int);
void showall();
void rev();
void revlist();
void main()
{
    insertAtE(10);
    insertAtE(20);
    insertAtE(30);
    insertAtE(40);
    insertAtE(50);
	showall();
	printf("\n.........................\n");
	//deleteAtB();
	//deleteAtE();
	//insertAtsp(7,121);
	//rev();
	revlist();
	//showall();
}
struct node *cn(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
	 return temp;
}
void insertAtB(int x)
{
struct node *temp=cn(x);
temp->prev=NULL;
if(start!=NULL)  
{
	start->prev=temp;
}
temp->next=start;
start=temp;	
}
void revshow(struct node *temp)
{
	if(temp==NULL)return;
	revshow(temp->next);
	printf("%d\n",temp->data);
}
void rev()
{
	struct node *temp=start;
	revshow(temp);
}
void revlist()
{
	struct node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
}

void showall()
{
	struct node *temp=start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void insertAtE(int x)
{
	if(start==NULL)
	{
		insertAtB(x);
		return;
	}
	struct node *temp=cn(x);
	temp->next=NULL;
	struct node *temp2=start;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	temp->prev=temp2;
	
}
void deleteAtB()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp=start;
	start=temp->next;
	start->prev=NULL;
	free(temp);
	
}
void deleteAtE()
{
	if(start==NULL)
	{
		deleteAtB();
		return;
	}
	struct node *temp=start;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}
int countnode()
{
	struct node *temp=start;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
void insertAtsp(int p,int x)
{
 	if(p<=1)
	{
		insertAtB(x);
		return;
	}
	else if(p>1 && p<countnode()+1)
	{
		struct node *temp=cn(x);
		struct node *temp2=start;
		int i;
		for(i=1;i<p-1;i++)
		{
			temp2=temp2->next;
		}
		temp->next=temp2->next;
		temp->prev=temp2;
		temp2->next->prev=temp;
		temp2->next=temp;

	}
	else
	{
		if(p!=countnode()+1)printf("pos is out of link so add at ending\n");
		insertAtE(x);
	}
}