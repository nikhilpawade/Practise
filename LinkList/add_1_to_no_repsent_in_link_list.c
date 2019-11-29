#include <stdio.h>
#include <stdlib.h>

struct add_no {
	int num;
	struct add_no *next;
};

struct add_no *head = NULL;

void print_link_list() {
	struct add_no * temp = head;
	
	while (temp) {
		printf("%d",temp->num);
		temp = temp->next;
	}
	printf("\n");
}

void reverse_link_list() {
	struct add_no *curr, *prev = NULL, *next;
	curr = head;
	

	while (curr != NULL) { 
		next = curr->next; // 3 4
		curr->next = prev;
		prev = curr; // 1 2 3
		curr = next;
	}
	head = prev;
}

void update_link_list(int digit) {
	struct add_no *temp, *temp1;
	temp = malloc(sizeof(struct add_no));
	temp->num = digit;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	} else {
		temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}

void print_digit(int number) {
	static int i = 0;
	int digit;
	digit = number % 10;
	number = number / 10;
	if ( number > 10) {
	print_digit(number );
	} else {
		printf("%d\n", number);
		update_link_list(number);
	}
	printf("%d\n",digit);
	update_link_list(digit);
}

int main() {
	int no, digit;
	printf("Enter the number\n");
	scanf("%d",&no);
	//ex:1234;
	print_digit(no);
	print_link_list();
	reverse_link_list();
	print_link_list();
}
