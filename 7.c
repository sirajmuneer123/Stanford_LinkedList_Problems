/*
Write an InsertSort() function which given a list, rearranges its nodes so they are sorted in
increasing order. It should use SortedInsert().
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
void SortedInsert(struct node** href,struct node* newNode);
void InsertSort(struct node**);
main()
{
	struct node* head=NULL;
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=6;
	struct node* new1,*new2,*new3;
	new1=malloc(sizeof(struct node));
	new1->data=7;
	new2=malloc(sizeof(struct node));
	new3=malloc(sizeof(struct node));
	newNode->next=new1;
	new2->data=5;
	new1->next=new2;
	new3->data=8;
	new2->next=new3;
	new3->next=NULL;
	InsertSort(&newNode);
	while(newNode!=NULL){
		printf("%d   ",newNode->data);
		newNode=newNode->next;
	}
}
void InsertSort(struct node** href)
{
	struct node* result=NULL;
	struct node* current=*href;
	struct node* next;
	while(current!=NULL){
		next=current->next;
		SortedInsert(&result,current);
		current=next;
	}
	*href=result;
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
		newNode->next=current->next;
		current->next=newNode;
		
	}

}
