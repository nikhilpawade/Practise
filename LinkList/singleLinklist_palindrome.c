#include <stdio.h>
#include <stdlib.h>

struct st {
	int no;
	struct st *next;
} *head;

int middle_num() {
	struct st *slow, *fast;
	slow = fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		printf(" %d %d\n",slow->no, fast->no);
	}
	return slow->no;
}
void insert(int num) {
	struct st *temp, *temp1;
	temp = malloc(sizeof(struct st));
	temp->no = num; 
	if (head == NULL) {
		head = temp;
		head->next = NULL;
	} else {
		temp1 = head;
		while(temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = NULL;
	}
	
}

int delete(int num) {
	struct st *temp, *prev;
	temp  = head;
	while(temp) {
		if (temp->no == num) {
			if (temp == head) {
				head = temp->next;
				free(temp);
				return 1;
			} else {
				prev->next = temp->next;
				free(temp);
				return 1;
			}
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
	return 0;
}

void size() {
	struct st *temp = head;
	int count = 0;
	while (temp) {
		temp = temp->next;
		count++;
	}
	printf("Size of single link list = %d\n",count);
}

void print() {
	struct st *temp = head;
	while (temp) {
		printf("%d ",temp->no);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	int ch, num;
	head = NULL;
	while(1) {
		printf("\nList Operations\n");
		printf("===============\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Size\n");
		printf("4.Delete\n");
		printf("5.Middle_no\n");
		printf("6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
	
		switch(ch) {
			case 1:
				printf("Enter the number to insert\n");
				scanf("%d", &num);
				insert(num);
				break;
			case 2:
				if (head == NULL) {
					printf("Link list is Empty\n");
					break;
				} else {
					print();
					break;
				}
			case 3:
				size();
				break;
			case 4:
				printf("Enter the number to delete\n");
				scanf("%d",&num);
				if (head == NULL) {
					printf("List is empty\n");
				} else {
					if (delete(num)) {
						printf("Num = %d delete from list\n",num);
						print();
					} else {
						printf("Num = %d Not found in list\n",num);
					}
				}
				break;
			case 5:
				if (head == NULL) {
					printf("Link list is empty\n");
					break;
				} else {
					num = middle_num();
					printf("Middle number is %d\n",num);
					break;
				}
			case 6:
				return 0;		
		}
	}
	return 0;
}
