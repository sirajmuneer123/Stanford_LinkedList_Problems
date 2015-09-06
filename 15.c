/*
(This problem requires recursion) Given FrontBackSplit() and SortedMerge(), it's pretty
easy to write a classic recursive MergeSort(): split the list into two smaller lists,
recursively sort those lists, and finally merge the two sorted lists together into a single
sorted list. Ironically, this problem is easier than either FrontBackSplit() or
SortedMerge().
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void MergeSort(struct node**);
struct node *BuildList(void);
struct node *SortedMerge(struct node*,struct node*);
void FrontBackSplit(struct node*,struct node**,struct node**);
int Length(struct node*);
void MoveNode(struct node**,struct node**);
main()
{
	struct node* head=BuildList();
	MergeSort(&head);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef)
{
	struct node* current=source;
	int len=Length(source);
	int size,i;	
	if(len%2!=0)
		size=(len/2)+1;
	else
		size=len/2;
	if(source!=NULL && len>1){
		*frontRef=source;
		for(i=1;current->next!=NULL && i<size;i++)
			current=current->next;
		*backRef=current->next;
		current->next=NULL;
	}else
		printf("error List is null!!\n");
	
}
struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node dummy;
	struct node* tail=&dummy;
	dummy.next=NULL;
	while(1){
		if(a==NULL){
			tail->next=b;
			break;
		}else if(b==NULL){
			tail->next=a;
			break;
		}
		if(a->data <= b->data){
			MoveNode(&(tail->next),&a);
			tail=tail->next;
		}else{
			 MoveNode(&(tail->next),&b);
			 tail=tail->next;
		}
	}
		return (dummy.next);
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
void MergeSort(struct node** headRef) 
{
	struct node* head = *headRef;
	struct node* a;
	struct node* b;
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef= SortedMerge(a, b);
}
int Length(struct node* head)
{
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
struct node *BuildList(void)
{
	struct node *one,*two,*three;
	one=malloc(sizeof(struct node));
	two=malloc(sizeof(struct node));
	three=malloc(sizeof(struct node));
	one->data=33;
	one->next=two;
	two->data=44;
	two->next=three;
	three->data=11;
	three->next=NULL;
	return one;
}
