/*
Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.
*/
struct node{
	int data;
	struct node *next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *BuildOneTwoThree(void);
void RecursiveReverse(struct node**);
main()
{
	struct node* head=BuildOneTwoThree();
	RecursiveReverse(&head);
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
void RecursiveReverse(struct node** headRef) 
{
	struct node* first;
	struct node* rest;
	if (*headRef == NULL) 
		return;
	first = *headRef;
	rest = first->next;
	if (rest == NULL) 
		return;
	RecursiveReverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*headRef = rest;
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
