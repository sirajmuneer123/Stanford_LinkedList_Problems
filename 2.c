/*
Write a GetNth() function that takes a linked list and an integer index and returns the data
value stored in the node at that index position. GetNth() uses the C numbering convention
that the first node is index 0, the second is index 1, ... and so on. So for the list {42, 13,
666} GetNth() with index 1 should return 13. The index should be in the range [0..length-
1]. If it is not, GetNth() should assert() fail (or you could implement some other error
case strategy).
*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *BuildOneTwoThree(void);
void GetNthTest(void);
int GetNth(struct node *,int index);
main()
{
	GetNthTest();
}
void GetNthTest(void)
{
	struct node *MyList = BuildOneTwoThree();
	int LastNode =GetNth(MyList,1);
	printf("%d\n",LastNode);
}
int GetNth(struct node *head,int index)
{
	struct node *dummy;
	int count=0;
	dummy=head;
	while(dummy!=NULL){
		++count;
		dummy= dummy->next;
	}
	int i=0;
	if(head==NULL){
		printf("errorrr!!   empty list \n");
		return 0; 		
	}
	else if(count<index+1){
		printf("errorrr!! index out of range: \n");	
		return 0;
	}
	else
		while(head!=NULL){
			if(i==index)
				return head->data;
			else{
				head=head->next;
				++i;
			}
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
