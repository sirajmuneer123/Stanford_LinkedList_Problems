/*
Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
and then sets 'b' to NULL (since it is now trailing off the end of 'a'). Here is a drawing of
a sample call to Append(a, b) with the start state in gray and the end state in black. At the
end of the call, the 'a' list is {1, 2, 3, 4}, and 'b' list is empty.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *BuildOneTwoThree(void);
void Append(struct node**,struct node**);
main()
{
	struct node *a=BuildOneTwoThree();
	struct node *b=BuildOneTwoThree();
	struct node* c;
	Append(&a,&b);
	while(a!=NULL){
		printf("%d\n",a->data);
		a=a->next;
	}
}
void Append(struct node** ar,struct node** br)
{
	if(*ar==NULL)
		*ar=*br;
	else{
		struct node *current=*ar;
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=*br;
	*br=NULL;
	}
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
