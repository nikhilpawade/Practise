#include <stdio.h>
#include <stdlib.h>

struct st {
	int num;
	struct st *next;
};

void push(struct st **node, int num) {
	struct st *temp = malloc(sizeof(struct st));
	temp->num = num;
	temp->next = *node;
	*node = temp;
}

void print(struct st *head) {
	while(head != NULL) {
		printf("%d ",head->num);
		head = head->next;
	}
	printf("\n");
}

void bubble_sort(struct st *node) {
	struct st *temp;
	int trav, temp1;
	if (temp == NULL) {
		return;
	}

	do {
		trav = 0;
		temp = node;
		while (temp->next != NULL) {
			if (temp->num > temp->next->num) {
				temp1 = temp->num;
				temp->num = temp->next->num;
				temp->next->num = temp1;
				trav = 1;
			}
			temp = temp->next;
	
		}

	} while(trav);
}

int main()
{
	struct st *head = NULL;
	push(&head, 9);
	push(&head, 10);
	push(&head, 4);
	push(&head, 99);
	push(&head, 3);
	push(&head, 12);
	push(&head, 5);
	push(&head, 15);
	push(&head, 7);
	push(&head, 8);
	push(&head, 34);

	printf("Link list before sort\n");
	print(head);
	bubble_sort(head);
	printf("Link list After sort\n");
	print(head);
	return 0;
	
}
