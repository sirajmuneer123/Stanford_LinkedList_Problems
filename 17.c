/*
Reverse the given linked list by changing its .next pointers and
its head pointer. Takes a pointer (reference) to the head pointer.
*/
struct node{
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void Reverse(struct node**);
void Push(struct node**,int);
struct node *BuildOneTwoThree(void);
void ReverseTest(void);
main()
{
	ReverseTest();
}
void ReverseTest(void)
{
	struct node* head=BuildOneTwoThree();
	struct node *f;
	Reverse(&head);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
void Reverse(struct node** headRef)
{
	struct node* current=*headRef;
	struct node* dummy=NULL;
	while(current!=NULL){
		Push(&dummy,current->data);
		current=current->next;
	}
	*headRef=dummy;
	
}
void Push(struct node** href,int data)
{
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=*href;
	*href=newNode;
	
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
