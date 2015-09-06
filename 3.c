/*
Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list).
*/
struct node {
	int data;
	struct node *next;
};
#include<stdio.h>
#include<stdlib.h>
struct node *BuildOneTwoThree(void);
void DeleteListTest(void);
void DeleteList(struct node **);
main()
{
	DeleteListTest();
}
void DeleteListTest(void)
{
	struct node* MyList=BuildOneTwoThree();
	DeleteList(&MyList);
	printf("yessssssssss\n");
	while(MyList!=NULL){
		printf("%d\n",MyList->data);
	}
}
void DeleteList(struct node **href)
{
	while(*href!=NULL){
		free(*href);
		*href=(*href)->next;
	}
	*href=NULL;
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
