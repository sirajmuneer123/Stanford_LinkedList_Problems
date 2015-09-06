/*
Write a Count() function that counts the number of times a given int occurs in a list. The
code for this has the classic list traversal structure as demonstrated in Length().
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *BuildOneTwoThree(void);
int count(struct node *,int );
main()
{
	struct node *head,*dummy;
	head=BuildOneTwoThree();
	dummy=head;
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n%d\n",count(dummy,1));
}
int count(struct node *head,int num)
{
	int times=0;
	while(head!=NULL){
		if((head->data)==num)
			++times;
		head=head->next;
	}

	return times;
}
struct node *BuildOneTwoThree(void)
{
	struct node *one,*two,*three;
	one=malloc(sizeof(struct node));
	two=malloc(sizeof(struct node));
	three=malloc(sizeof(struct node));
	one->data=1;
	one->next=two;
	two->data=1;
	two->next=three;
	three->data=3;
	three->next=NULL;
	return one;
}
