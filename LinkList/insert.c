#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st {
	int rollno;
	char name[10];
	struct st *next;
};

void add_begin(struct st ** ptr) {
	struct st *temp;
	temp = malloc(sizeof(struct st ));
	printf("Enter the roll no\n");
	scanf("%d",&(temp->rollno));
	printf("Enter the name\n");
	scanf("%s",temp->name);
	temp->next = *ptr;
	*ptr = temp;

}

void add_end(struct st **ptr) {
	struct st *temp,*ptr1;
	temp = malloc(sizeof(struct st));
	printf("Enter the roll no\n");
	scanf("%d",&(temp->rollno));
	printf("Enter the name\n");
	scanf("%s",temp->name);
	if(*ptr == NULL) {
		temp->next = *ptr;
		*ptr = temp;
	} else {
		ptr1 = *ptr;
		while(ptr1->next != NULL) {
			ptr1 = ptr1->next;
		}
		ptr1->next = temp;
		temp->next = NULL;

	}



}

void insert(struct st **ptr) {

	struct st *temp,*curent_ptr,*previos_ptr;
	temp = malloc(sizeof(struct st));
	printf("Enter the roll no\n");
	scanf("%d",&(temp->rollno));
	printf("Enter the name\n");
	scanf("%s",temp->name);
	if(*ptr == NULL || ( temp->rollno < (*ptr)->rollno) ) {
		temp->next = *ptr;
		*ptr = temp;
	} else {
		curent_ptr = *ptr;
		while(curent_ptr->next != NULL && (temp->rollno > curent_ptr->rollno)) {
			previos_ptr = curent_ptr;
			curent_ptr = curent_ptr->next;
			
		}
		if(curent_ptr->rollno > temp->rollno) {
			temp->next = curent_ptr;
			previos_ptr->next = temp;
		} else {
			temp->next = NULL;
			curent_ptr->next = temp;
			
		}
		
		printf("333\n");
	
	}
	


}

void print(struct st *ptr) {

	
	while(ptr) {
		printf("%d %s\n",ptr->rollno,ptr->name);
		ptr = ptr->next;


	}

}

main() {
	struct st *hedptr=NULL ;
	hedptr = malloc(sizeof(struct st));
	hedptr->rollno = 11;
	strcpy(hedptr->name,"ABC");
	add_begin(&hedptr);
	print(hedptr);
	printf("---------------------------\n");
	add_end(&hedptr);
	print(hedptr);
	printf("----------------------\n");
	insert(&hedptr);
	printf("----------------------\n");
	print(hedptr);

}
