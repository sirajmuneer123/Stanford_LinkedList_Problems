/*
A more difficult problem is to write a function InsertNth() which can insert a new node at
any index within a list. Push() is similar, but can only insert a node at the head end of the
list (index 0). The caller may specify any index in the range [0..length], and the new node
should be inserted so as to be at that index.
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
void InsertNthTest(void);
void InsertNth(struct node** HeadRef,int index,int data);
void Push(struct node** ,int data);
void DeleteList(struct node**);
main()
{
	InsertNthTest();
}
void InsertNthTest() {
	struct node* head = NULL;
	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	DeleteList(&head);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}

}
void DeleteList(struct node **href)
{
	struct node* current=*href;
	struct node* next;
	while(current!=NULL){
		next=current->next;
		free(current);
		current=next;
		
	}
	*href=NULL;
}
void Push(struct node** headRef,int data)
{
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=*headRef;
	*headRef=newNode;
}
void InsertNth(struct node** headRef, int index, int data) {
	if (index == 0) 
		Push(headRef, data);
	else {
		struct node* current = *headRef;
		int i;
		for (i=0; i<index-1; i++)
			current = current->next;
		Push(&(current->next), data); 
	}
}
