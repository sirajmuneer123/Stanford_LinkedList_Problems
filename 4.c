/*
Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data. If all you ever used were Push() and
Pop(), then our linked list would really look like a stack. However, we provide more
general functions like GetNth() which what make our linked list more than just a stack.
Pop() should assert() fail if there is not a node to pop. Here's some sample code which
calls Pop()....
*/
struct node {
	int data;
	struct node *next;
};
#include<stdio.h>
#include<stdlib.h>
void PopTest(void);
int Pop(struct node **HeadRef);
struct node *BuildOneTwoThree(void);
int Length(struct node *);
main()
{
	PopTest();
}
void PopTest(void)
{
	struct node* head=BuildOneTwoThree();
	int a = Pop(&head);
	int b = Pop(&head); 
	int c = Pop(&head);
	int len = Length(head);
}
int Length(struct node *head)
{
	struct node* current=head;
	int count = 0;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;
}
int Pop(struct node **HeadRef)
{
	int val;
	if(*HeadRef!=NULL)
	{
		val=(*HeadRef)->data;
		free(*HeadRef);
		*HeadRef=(*HeadRef)->next;
	}else
		printf("error!!! list empty..\n");
	return val;
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
