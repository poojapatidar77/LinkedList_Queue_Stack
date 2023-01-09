//singly linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insertAtB(int);
void showall();
void insertAtE(int);
void deleteAtB();
void deleteAtE();
int countnode();
void insertAtsp(int ,int);
void deleteAtsp(int);
int searchnode(int);
void rev();
void revlist();
int max();
int min();
void sort();
void main()
{
	//insertAtB(10);
	//insertAtB(20);
	//insertAtB(30);
	//insertAtB(40);
	 //insertAtB(50);
   // showall();
 insertAtE(10);
	insertAtE(220);
	insertAtE(130);
	insertAtE(420);
	insertAtE(50);
	 showall();    
     printf("\n......................\n");
   //  deleteAtE();
//showall();
     //printf("%d\n",countnode());	 
    // insertAtsp(11,121);
	 //deleteAtsp(3);
	 //showall();
    // printf("%d\n",searchnode(70));
    //  rev();
     //  revlist();
	 //printf("%d\n",max());
	 //printf("%d\n",min());
	   sort();
	   showall();
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
	temp->next=start;
	start=temp;
}
void sort()
{
	struct node *temp=start;
	struct node *temp2=temp->next;

	int i,j,t,min;
	for(i=1;i<countnode();i++)
	{  
        min=temp->data;
		while(temp2!=NULL)
		{
			if((temp->data)>(temp2->data))
			{
				t=temp->data;
				temp->data=temp2->data;
			   temp2->data=t;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
		temp2=temp->next;
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
int min()
{
	
	struct node *temp=start;
	int min=temp->data;
     temp=temp->next;
	while(temp!=NULL)
	{
		if(min>(temp->data))min=temp->data;
		temp=temp->next;
	}
	return min;
	
}
int max()
{
	struct node *temp=start;
	int max=temp->data;
     temp=temp->next;
	while(temp!=NULL)
	{
		if(max<(temp->data))max=temp->data;
		temp=temp->next;
	}
	return max;
	
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
}

void deleteAtB()
{
	if(start ==NULL)
	{
		printf("list is empty \n");
		return;
	}
	struct node *temp=start;
	 start=temp->next;
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
	 
	else if(p>1&&p<=countnode()+1)
	{
	struct node *temp=cn(x);
	struct node *temp2=start;
	int i;
	for(i=1;i<p-1;i++)
	{
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
	}
	else{
		printf("position is out of range so insert at ending\n");
		insertAtE(x);
	}
}
void deleteAtsp(int p)
{
	if(start ==NULL)
	{
		deleteAtB();
		return;
	}
	struct node *temp=start;
	struct node *temp2;
	int i;
	for(i=1;i<p;i++)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=temp->next;
	free(temp);
}
int searchnode(int x)
{
	struct node *temp=start;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		if(temp->data==x)return c;
		temp=temp->next;
	}
	return -1;
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
	struct node *temp2=NULL;
	struct node *temp3;
	while(temp!=NULL)
	{
		temp3=temp->next;
		temp->next=temp2;
		temp2=temp;
		temp=temp3;
	}
	start=temp2;
}