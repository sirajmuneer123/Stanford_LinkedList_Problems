/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
struct node{
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void AlternatingSplit(struct node*,struct node**,struct node**);
struct node *BuildOneTwoThree(void);
void MoveNode(struct node**,struct node**);
main()
{
	struct node* head=BuildOneTwoThree();
	struct node* a=NULL;
	struct node* b=NULL;
	AlternatingSplit(head,&a,&b);
	printf("odd position list : ");
	while(a!=NULL){
		printf("%d ",a->data);
		a=a->next;
	}
	printf("\neven position list : ");
	while(b!=NULL){
		printf("%d\n",b->data);
		b=b->next;
	}
	
}
void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef)
{
	struct node* current=source;
	struct node* a=NULL;
	struct node* b=NULL;
	if(source!=NULL)
		while(current!=NULL){
			MoveNode(&a,&current);
			if(current!=NULL)
				MoveNode(&b,&current);
				
		}	
	else
		printf("list is empty...\n");
	*aRef=a;
	*bRef=b;
}
void MoveNode(struct node** destRef, struct node** sourceRef)
{
	struct node* newNode=*sourceRef; 
	if(newNode!=NULL)
	{
		*sourceRef=newNode->next;
		newNode->next=*destRef;
		*destRef=newNode;
	}
	else
		printf("list is empty...\n");
		
}
struct node *BuildOneTwoThree(void)
{
	struct node *one,*two,*three;
	one=malloc(sizeof(struct node));
	two=malloc(sizeof(struct node));
	three=malloc(sizeof(struct node));
	one->data=1;
	one->next=two;
	two->data=2;
	two->next=three;
	three->data=3;
	three->next=NULL;
	return one;
}
