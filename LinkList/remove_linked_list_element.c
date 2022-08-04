#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


int print(struct ListNode *head) {

		while(head) {
			printf(" %d ", head->val);
			head = head->next;
		}

		printf("\n");

	return 0;


}
//  1  2  3  6  4 
struct ListNode* removeElements(struct ListNode* head, int val){

	struct ListNode *tmp = head, *previ = NULL;
    
    while (tmp != NULL) {
        if (tmp->val == val) {
            if (previ == NULL) {
                head = tmp->next;
                free(tmp);
                tmp = head;
            } else {
                previ->next = tmp->next;
                free(tmp);
                tmp = previ->next;
            }
            
        } else {
            previ = tmp;
            tmp = tmp->next;
        } 
    }
    
    return head;
}

struct ListNode* insert (struct ListNode* head, int val) {
	struct ListNode *tmp = NULL, *ptr = head;
	tmp = malloc(sizeof(struct ListNode));
	tmp->val = val;
	tmp->next = NULL;

	if (head == NULL) {
		head = tmp;
	} else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = tmp;
	}

	return head;
}

int main()
{
	struct ListNode *head = NULL, *tmp = NULL;
	
	int option, val;
	
	while (1) {
		printf("Enter the option 0->insert, 1->remove, 2->print 3->exit\n");
		scanf("%d",&option);
		if (option == 0) {
			printf("Enter value to insert\n");
			scanf("%d", &val);
			head = insert(head, val); 
		} else if (option == 1) {
			printf("Enter the value to delte\n");
			scanf("%d", &val);
			head = removeElements(head, val);
		} else if (option == 2) {
			print(head);

		} else {
			break;
		}

	
	}

	return 0;	
}
