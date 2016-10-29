#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };
void P(struct ListNode *x) {
	while(x) {
		printf("%d ", x->val);
		x = x->next;
	}
	putchar('\n');
}
struct ListNode *reverseList(struct ListNode *x) {
	struct ListNode *A = NULL, *B = NULL;
	while(x) {
		A = x;
		x = x->next;
		A->next = B;
		B = A;
	}
	return A;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int d = 0;
	struct ListNode *head = NULL, *ptr = NULL;
	if(!l1 && l2) return l2;
	if(!l2 && l1) return l1;
	l1 = reverseList(l1), l2 = reverseList(l2);
	while(l1 && l2) {
		int v = l1->val + l2->val + d;
		d = v / 10;
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp->val = v %= 10;
		temp->next = NULL;
		if(!head) {
			ptr = head = temp;
		} else {
			ptr->next = temp;
		}
		ptr = temp;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1) {
		int v = l1->val + d;
		d = v / 10;
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp->val = v %= 10;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		l1 = l1->next;
	}
	while(l2) {
		int v = l2->val + d;
		d = v / 10;
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp->val = v %= 10;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		l2 = l2->next;
	}
	if(d) {
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp->val = d;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
	}
	return reverseList(head);
}
int main() {
	int i;
	struct ListNode Arr[2][4];
	for(i = 0; i < 4; i++) {
		if(i < 3) {
			Arr[0][i].val = rand() % 10;
			Arr[0][i].next = &Arr[0][i + 1];
		} else {
			Arr[0][i].val = rand() % 10, Arr[0][i].next = NULL;
		}
		if(i < 3) {
			Arr[1][i].val = rand() % 10;
			Arr[1][i].next = &Arr[1][i + 1];
		} else {
			Arr[1][i].val = rand() % 17, Arr[1][i].next = NULL;
		}
	}
	struct ListNode *A = &Arr[0][0];
	struct ListNode *B = &Arr[1][0];
	P(A); P(B);
	P(addTwoNumbers(A, B));
	return 0;
}
