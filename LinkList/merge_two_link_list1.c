#include  <stdio.h>
#include <stdlib.h>
struct st {
	int num;
	struct st *next;

};

void insert(int num, struct st **node)
{
	struct st *tmp, *tmp1;
	tmp = *node;

	tmp1 = malloc(sizeof(struct st));
	tmp1->num = num;
	if (*node == NULL || num <= (*node)->num) {
		tmp1->next = *node;
		*node = tmp1;
	} else {
		while (tmp->next != NULL && tmp->next->num <= num) {
			tmp = tmp->next;
		}
		tmp1->next = tmp->next;
		tmp->next = tmp1;
		
	}
}

void print(struct st *node)
{
	while(node != NULL){
		printf("%d ", node->num);
		node = node->next;
	}

}

void movepointer(struct st **dest, struct st **sour)
{
	struct st *newnode = *sour;
	*sour = newnode->next;
	newnode->next = *dest;
	*dest = newnode;
	



}

struct st * mergelinklist(struct st *node1, struct st *node2)
{
	struct st *result = NULL;
	struct st **lastref = &result;
	
	while (1) {
		if (node1 == NULL) {
			*lastref = node2;
			break;
		} else if (node2 == NULL) {
			*lastref = node1;
			break;
		}
		if (node1->num <= node2->num) {
			movepointer(lastref, &node1);	
		} else {
			movepointer(lastref, &node2);
		}
		lastref = &((*lastref)->next);
	 
	}
	return result;
}

struct st *_mergelinklist1(struct st *node1, struct st *node2)
{
	if (!node1->next) {
        	node1->next = node2;
        	return node1;
    	}
	struct st *curt1 = node1, *curt2 = node2, *next1 = curt1->next, *next2 = curt2->next;

	
	while(next1 && curt2) {
		if (curt1->num <= curt2->num && next1->num >= curt2->num) {
			next2 = curt2->next;	
			curt1->next = curt2;
			curt2->next = next1;

			curt1 = curt2;
			curt2 = next2;
		} else {
			if (next1->next) {
				next1 = next1->next;
				curt1 = curt1->next;
			} else {
				next1->next = curt2;
				return node1;
			}
		}

	}
	return node1;	

}
struct st *mergelinklist1(struct st *node1, struct st *node2)
{	
	if (node1 == NULL) {
		return node2;
	}
	if (node2 == NULL) {
		return node1;
	}

	if (node1->num < node2->num) {
		return _mergelinklist1(node1, node2);
	} else {
		return _mergelinklist1(node2, node1);
	}
}
int main()
{
	int i, num;
	struct st *node1 = NULL, *node2 = NULL, *node3 = NULL;
	printf("Enter the 6 number\n");
	for (i = 0; i < 6; i++) {
		scanf("%d",&num);
		insert(num, &node1);
	}
	print(node1);
	printf("\n");
	printf("Enter the 6 number\n");	
	for (i = 0; i < 6; i++) {
		scanf("%d ",&num);
		insert(num, &node2);
	}
	print(node2);
	
	node3 = mergelinklist(node1, node2);
	
	print(node3);

	node3 = NULL;
	node3 = mergelinklist1(node1, node2);

	print(node3);
}
