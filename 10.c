/*
remove duplicates from a sorted list.
*/
struct node{
	int data;
	struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void RemoveDuplicates(struct node*);
struct node *BuildList(void);
main()
{
	struct node* head=BuildList();
	RemoveDuplicates(head);
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
void RemoveDuplicates(struct node* head) 
{
	struct node* current=head;
	struct node* temp;
	if(current!=NULL)
		while(current->next!=NULL){
			if(current->data == current->next->data){
			//	temp=current->next->next;
				free(current->next);
				current->next=current->next->next;
			}
			else
				current=current->next;
		}
	else
		printf("error...List is empty!!");
}
struct node *BuildList(void)
{
	struct node *one,*two,*three;
	one=malloc(sizeof(struct node));
	two=malloc(sizeof(struct node));
	three=malloc(sizeof(struct node));
	one->data=20;
	one->next=two;
	two->data=22;
	two->next=three;
	three->data=22;
	three->next=NULL;
	return one;
}
