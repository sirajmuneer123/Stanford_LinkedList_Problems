/*
Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.
*/
struct node {
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void MoveNodeTest(void);
void MoveNode(struct node**,struct node**);
struct node *BuildOneTwoThree(void);
main()
{
	MoveNodeTest();
}
void MoveNodeTest(void)
{
	struct node* a=NULL;//BuildOneTwoThree();
	struct node* b=BuildOneTwoThree();
	MoveNode(&a,&b);
	while(a!=NULL){
		printf("%d ",a->data);
		a=a->next;
	}
	printf("\n");
	while(b!=NULL){
		printf("%d ",b->data);
		b=b->next;
	}
	printf("\n");
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
	one->data=11;
	one->next=two;
	two->data=2;
	two->next=three;
	three->data=1;
	three->next=NULL;
	return one;
}

