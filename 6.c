/*
Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
void SortedInsert(struct node** href,struct node* newNode);
main()
{
	struct node* head=NULL;
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=6;
	SortedInsert(&head,newNode);
	struct node* new1,*new2,*new3;
	new1=malloc(sizeof(struct node));
	new1->data=7;
	SortedInsert(&head,new1);
	new2=malloc(sizeof(struct node));
	new3=malloc(sizeof(struct node));
	new2->data=9;
	SortedInsert(&head,new2);
	new3->data=8;
	SortedInsert(&head,new3);
	while(head!=NULL){
		printf("%d   ",head->data);
		head=head->next;
	}
}
void SortedInsert(struct node** href,struct node* newNode)
{
	if(*href==NULL||newNode->data <= (*href)->data){
		newNode->next=*href;
		*href=newNode;
	}else{
		struct node* current=*href;
		struct node* pr;
		while(current->next !=NULL && current->next->data < newNode->data){
				current=current->next;
		}
		printf("ss%d\n",current->data);
		newNode->next=current->next;
		current->next=newNode;
		
	}

}

