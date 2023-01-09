//xor linked list


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *xor;
};
struct node *start=NULL;
struct node *end=NULL;
void insert(char);
void insertAtB(char);
void showall();
void rshowall();
void main()
{
	 //insert('A');
	 //insert('B');
	 //insert('C');
	 //insert('D');
	 //insert('E');
	 insertAtB('A');
	 insertAtB('B');
	 insertAtB('C');
	 insertAtB('D');
	 insertAtB('E');
	 showall();
	 printf("\n.............\n");
     rshowall();
}
void insert(char c)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=c;
   if(start==NULL)
   {
	   end =start=temp;
	   temp->xor=0;
	   return ;
   }
   end->xor=  (struct node *)((uintptr_t)(end->xor)^(uintptr_t)temp); 
   temp->xor=(struct node *)((uintptr_t)end^0);
   //   temp->xor=end;

   end =temp;
}
void insertAtB(char c)
{
	struct node *temp=malloc(sizeof(struct node));
       temp->data=c;	
	if(start==NULL)
	 {
		 end =start=temp;
		 temp->xor=0;		
		return;
	 }
	 start->xor = (struct node *)((uintptr_t)(start->xor)^(uintptr_t)temp); 
	 //temp->xor=(struct node*)((uintptr_t)start^0);
	  temp->xor=start;
	 start=temp;
}
void showall()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp=start;
	struct node *prev=0;
	struct node *prev2;
	while(temp!=end)
	{
		printf("%c\n",temp->data);
		prev2=temp;
		temp= (struct node *)((uintptr_t)prev^(uintptr_t)(temp->xor));
		prev=prev2;
	}
			printf("%c\n",temp->data);

}
void rshowall()
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp=end;
	struct node *prev=0;
	struct node *prev2;
	while(temp!=start)
	{
		printf("%c\n",temp->data);
		prev2=temp;
		temp= (struct node *)((uintptr_t)prev^(uintptr_t)(temp->xor));
		prev=prev2;
	}
			printf("%c\n",temp->data);

}