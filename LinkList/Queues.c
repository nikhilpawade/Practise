#include<stdio.h>
struct st {
	int rollNo;
	struct student *next;
}*front,*rear,*temp,*front1;
void create();
void enqueue( int no);
void display();
void dequeue();
int count = 0;
main() 
{
	int ch,no;
	printf("1-- Enque\n");
	printf("2-- Deque\n");
	printf("3 -- Front element\n");
	printf("4 - Empty\n");
	printf("5 - Exit\n");
	printf("6 - Display\n");
	printf("7 - Queue size\n");
	create();
	while(1) {
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data\n");
				scanf("%d",&no);
				enqueue(no);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				exit(0);
			case 6:
				display();
				break;
			case 7:
				break;
			default:
				printf("Wrong Choice,Please enter the correct choice\n");
				break;
		}
	}
		

}

/* Crate Empty node */
void create() {
	front = rear = NULL;
}

void dequeue() {
	front1 = front;
	if(front1 == NULL) {
		printf("Empty queue \n");
		return;
	} else {
		if(front1->next != NULL) {
			front1 = front1->next;
			printf("Dequeue Roll No %d\n",front->rollNo);
			free(front);
			front = front1;
		} else {
			printf("Dequeue Roll No %d\n",front->rollNo);
			free(front);
			front = rear = NULL;

		}
		
	}
	count --;
}

void enqueue( int no) {
	if(rear == NULL) {
		rear = (struct st *)malloc(sizeof(struct st));
		rear->next = NULL;
		rear->rollNo = no;
		front = rear;

	} else {
		temp = (struct st *)malloc(sizeof(struct st));
		rear->next = temp;
		temp->rollNo = no;
		temp->next = NULL;
		rear = temp;


	}
	
	count ++;

}
	
void display() {
	front1 = front;
	if ((front1 == NULL) && (rear == NULL)) {
		printf("Queu is empty\n");
		return;
	}
	while(front1 != rear) {
		printf("RollNO = %d  ",front1->rollNo);
		front1 = front1->next;
	}

	if(front1 == rear) {
		printf("RollNo = %d  ",front1->rollNo);
	}

}

