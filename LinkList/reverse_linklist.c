#include<stdio.h>
#include<stdlib.h>
struct st {
	int num;
	struct st *next;
};


insert(struct st **ptr) {
	struct st *tmp,*cptr;
	tmp = malloc(sizeof(struct st));
	printf("Enter the number to insert\n");
	scanf("%d",&(tmp->num));
	if(*ptr == NULL || (tmp->num <= (*ptr)->num)  ) {
		tmp->next = *ptr;
		*ptr = tmp;
	} else {
		
		cptr = *ptr;
		while(cptr->next != NULL && tmp->num > cptr->next->num) {
			cptr = cptr->next;
		} 
		tmp->next = cptr->next;
		cptr->next = tmp;	
	}

}
print(struct st *ptr) {
	while(ptr) {
		printf("%d ",ptr->num);
		ptr = ptr->next;
	}
	printf("\n");

}
reverse(struct st **ptr) {
	struct st *prev = NULL;
	struct st *current,*next;
	current = *ptr;
	
	while(current != NULL) {

		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}
	*ptr = prev;
}

main()
{
	struct st *head = NULL;
	head = malloc(sizeof(struct st));
	head->num = 10;
	head->next = NULL;
	insert(&head);	
	print(head);
	reverse(&head);
	print(head);












}
