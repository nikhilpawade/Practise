#include <stdio.h>
#include <stdlib.h>
struct st {
	int no;
	struct st *next;
};

int find_loop(struct st *head)
{
	struct st *tmp, *tmp1;
	tmp = head;
	tmp1 = head;
	while (tmp && tmp1 && tmp1->next) {
		tmp = tmp->next;
		tmp1 = tmp1->next->next;
		if ( tmp == tmp1) {
			printf("Loop find = %d\n", tmp->next->no);
		}
		return 1;
	}
	return 0;
}
int main()
{
	struct st *head, *tmp;
	head = (struct st*)malloc(sizeof (struct st));
	head->no = 1;
	
	tmp = (struct st*)malloc(sizeof (struct st));
	tmp->no = 2;
	head->next = tmp;
	tmp = (struct st*)malloc(sizeof (struct st));
	tmp->no = 2;

	head->next = tmp;
	tmp = (struct st*)malloc(sizeof (struct st));
	tmp->no = 3;
	head->next->next = tmp;

	tmp = (struct st*)malloc(sizeof (struct st));
	tmp->no = 4;
	head->next->next = tmp;

	tmp = (struct st*)malloc(sizeof (struct st));
	tmp->no = 5;
	head->next->next->next = tmp;
	tmp->next = head->next;

	find_loop(head);
	return 0;
}





