#include <stdio.h>
#include <stdlib.h>
struct st {
	int num;
	struct st *next;
};

int insert(int num, struct st **hptr) {
	struct st *temp = malloc(sizeof(struct st));
	struct st *temp1 = *hptr;

	temp->num = num;
	if ((temp1 == NULL) || (temp1->num >= num)) {
		temp->next = temp1;
		*hptr = temp;
	} else {
		while(temp1->next != NULL && temp1->next->num <= num) {
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp; 
	}
	return 0;	
}

int delete_num(int num, struct st **hptr) {
	struct st *temp = *hptr;
	struct st *prev = NULL;

	while(temp != NULL) {
		
		if (temp->num == num) {
			if(prev != NULL) {
				prev->next = temp->next;
				free(temp);
				temp = prev->next;
			} else {
				*hptr = temp->next;
				free(temp);
				temp = *hptr;
			}
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
	return 0;
}

int main() {
	struct st *head = NULL, *temp = NULL;
	int num;
	char ch;
	while (1) {
		printf("Enter the number to insert\n");
		scanf("%d", &num);
		insert(num, &head);
		printf("If you want to contin Enter Y/y\n");
		scanf(" %c", &ch);

		if ((ch != 'y') && (ch != 'Y')) {
			printf("----> %c \n", ch);
			break;
		}
		
	}
	temp = head;
	while (temp != NULL) {
		printf("%d  ",temp->num);
		temp = temp->next;	
	}

	printf("\n");
	printf("Enter the nuber to delete\n");
	scanf("%d", &num);
	delete_num(num, &head);
	
	temp = head;
	while (temp != NULL) {
		printf("%d  ",temp->num);
		temp = temp->next;	
	}
}
