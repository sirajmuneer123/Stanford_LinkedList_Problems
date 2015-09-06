/*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
*/
struct node{
	int data;
	struct node *next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *BuildOneTwoThree(void);
struct node *BuildOneTwo(void);
struct node *SortedMerge(struct node*,struct node*);
void MoveNode(struct node** ,struct node**);
main()
{
	struct node* head=NULL;
	struct node* a=BuildOneTwoThree();
	struct node* b=BuildOneTwo();
		head=SortedMerge(a,b);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
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
        one->data=33;
        one->next=two;
        two->data=44;
        two->next=NULL;
        return one;
}
