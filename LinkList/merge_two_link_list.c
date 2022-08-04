#include <stdio.h>
#include <stdlib.h>

struct st {
	int num;
	struct st *next;
};


void insert(struct st **node, int num) {
	struct st *temp1 = *node;
	struct st *temp = malloc(sizeof (struct st));
	temp->num = num;

	if ((*node == NULL) || ((*node)->num > num)) {
		temp->next = *node;
		*node = temp;
	} else {
		while (temp1->next != NULL && temp1->next->num < num) {
			temp1 = temp1->next;
		}

		temp->next = temp1->next;
		temp1->next = temp;
	}
}

void print_node(struct st *node) {
	while(node != NULL) {
		printf("%d\n", node->num);
		node = node->next;
	}
}
struct st * moveNode(struct st **destRef, struct st **sourceRef) {
	struct st *newnode = *sourceRef;
	
	*sourceRef = newnode->next;
	newnode->next = *destRef;
	
	*destRef = newnode;
}

struct st * merge_link_list(struct st *a, struct st *b) {
	struct st *result = NULL;
	struct st **lastref = &result;
	
	while(1) {
		if (a == NULL) {
			*lastref = b;
			break;
		} else if (b == NULL) {
			*lastref = a;
			break;
		} 

		if (a->num <= b->num) {
			moveNode(lastref, &a);
		} else {
			moveNode(lastref, &b);
		}
		lastref = &((*lastref)->next);

	}
	return (result);
	
}

int main() {
	int no, i;
	struct st *node1 = NULL, *node2= NULL, *node3;
	for (i=0; i < 6; i++) {
		printf("Enter the 6 number to insert in link list1\n");
		scanf("%d", &no);
		insert(&node1, no);
	}

	for (i=0; i < 6; i++) {
		printf("Enter the 6 number to insert in link list2\n");
		scanf("%d", &no);
		insert(&node2, no);
	}
	
	printf("Print Node 1\n");
	print_node(node1);

	printf("Print Node 2\n");
	print_node(node2);

	node3 = merge_link_list(node1, node2);

	printf("Print Merge Node \n");
	print_node(node3);
}
