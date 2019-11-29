#include <stdio.h>
#include <stdlib.h>

struct st {
	int data;
	struct st *next;
};

int print_node(struct st *tmp)
{
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return 0;
}

int find_length(struct st *tmp)
{
	int count = 0;
	while (tmp) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

int __getInterssectionNode(struct st *head1, struct st *head2, int d)
{
	int i;
	for (i = 0; i < d; i++) {
		if (head1 == NULL) {
			return -1;
		}
			head1 = head1->next;
	}
	while (head1!= NULL && head2!= NULL) {
		if (head1 == head2) {
			return head1->data;
		}
		head1 = head1->next;
		head2 = head2->next; 
	}
	return -1;
}

int getInterssectionNode(struct st *head1, struct st *head2)
{
	int c1 , c2, d;
	if (c1 > c2) {
		
	} else {
	}
	c1 = find_length(head1);	
	c2 = find_length(head2);
	if (c1 > c2) {
		d = c1 -c2;
		return __getInterssectionNode(head1, head2, d);
		
	} else {
		d = c2 -c1;
		return __getInterssectionNode(head2, head1, d);
	}
}
int main() 
{
//	3->6->9->15->30
//	     10->15->30
	struct st *head1, *head2, *newnode;
	head1 = (struct st*)malloc(sizeof(struct st));
	head1->data = 3;
	
	newnode = (struct st*)malloc(sizeof(struct st));
	newnode->data = 6;
	head1->next = newnode;
	
	newnode = (struct st*)malloc(sizeof(struct st));
	newnode->data = 9;
	head1->next->next = newnode;

	
	head2 = (struct st*)malloc(sizeof(struct st));
	head2->data = 10;

	newnode = (struct st*)malloc(sizeof(struct st));
	newnode->data = 15;
	head1->next->next->next = newnode;
	head2->next = newnode;

	newnode = (struct st*)malloc(sizeof(struct st));
	newnode->data = 30;
	head2->next->next = newnode;
	
	head2->next->next->next = NULL;

	print_node(head1);
	print_node(head2);
	
	printf("The node of intersection is %d \n", getInterssectionNode(head1, head2));
	return 0;
	
	
}
