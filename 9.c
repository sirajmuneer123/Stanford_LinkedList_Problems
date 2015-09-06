/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
struct node{
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *BuildOneTwoThree(void);
int Length(struct node*);
void FrontBackSplit(struct node*,struct node**,struct node**);
main()
{
	struct node* head=BuildOneTwoThree();
	struct node* front;
	struct node* back;
	FrontBackSplit(head,&front,&back);
	printf("front list is : ");
	while(front!=NULL){
		printf("  %d",front->data);
		front=front->next;
	}
	printf("\nBack list is : ");
	while(back!=NULL)
	{
		printf("  %d",back->data);
		back=back->next;
	}
	printf("\n");


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
int Length(struct node* head)
{
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
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
