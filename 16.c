/*
compute a new sorted list that represents the intersection
of the two given sorted lists.
*/
struct node{
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *SortedIntersect(struct node* a,struct node* b);
void Push(struct node**,int data);
struct node *BuildOneTwoThree(void);
struct node *BuildOneTwo(void);
main()
{
	struct node* a=BuildOneTwoThree();
	struct node* b=BuildOneTwo();
	struct node* head=NULL;
	head=SortedIntersect(a,b);
	while(head!=NULL){
		printf("%d  ",head->data);
		head=head->next;
	}
}
void Push(struct node** headRef,int data)
{
	struct node* newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=*headRef;
	*headRef=newNode;
}
struct node* SortedIntersect(struct node* a, struct node* b)
{
	struct node dummy;
	struct node* tail=&dummy;
	dummy.next=NULL;
	while(a!=NULL && b!=NULL){
		if(a->data == b->data){
			Push(&(tail->next),a->data);
			a=a->next;
			b=b->next;
			tail=tail->next;
		}else if(a->data > b->data){
			b=b->next;
		}else{
			a=a->next;
		}
	}
	return (dummy.next);
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
struct node *BuildOneTwo(void)
{
        struct node *one,*two,*three;
        one=malloc(sizeof(struct node));
        two=malloc(sizeof(struct node));
        three=malloc(sizeof(struct node));
        one->data=2;
        one->next=two;
        two->data=3;
        two->next=NULL;
        return one;
}
