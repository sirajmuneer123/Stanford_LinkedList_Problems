/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
struct node{
	int data;
	struct node *next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *BuildOneTwoThree(void);
struct node *BuildOneTwo(void);
struct node *ShuffleMerge(struct node*,struct node*);
void MoveNode(struct node** ,struct node**);
main()
{
	struct node* head=NULL;
	struct node* a=BuildOneTwoThree();
	struct node* b=BuildOneTwo();
		head=ShuffleMerge(a,b);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
struct node* ShuffleMerge(struct node* a, struct node* b)
{
	struct node dummy;
	struct node* tail=&dummy;
	dummy.next=NULL;
	while(1){
		if(a==NULL && b==NULL)
			return (dummy.next);
		else{
			if(a!=NULL){
			   MoveNode(&(tail->next),&a);
			   tail=tail->next;
			}
			if(b!=NULL){
			   MoveNode(&(tail->next),&b);
			   tail=tail->next;
			}
		}
	}
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
struct node *BuildOneTwo(void)
{
        struct node *one,*two,*three;
        one=malloc(sizeof(struct node));
        two=malloc(sizeof(struct node));
        three=malloc(sizeof(struct node));
        one->data=1;
        one->next=two;
        two->data=2;
        two->next=NULL;
        return one;
}

