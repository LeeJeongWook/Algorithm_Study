#include <iostream>

using namespace std;

typedef struct ListNode {
	int data;
	struct ListNode* next;
} ListNode;

int CircularListLength(ListNode* head) {
	int len = 0;
	ListNode* current = head;

	while (current != NULL) {
		len++;
		current = current->next;
	}

	return len;
}

void PrintList(ListNode* head) {
	if (head == NULL) {
		cout << "NULL\n";
		return;
	}

	ListNode* current = head;

	do {
		cout << current->data << " -> ";
		current = current->next;
	} while (current != head);
	cout << "HEAD\n";
}

void InsertAtHead(ListNode** head, int data) {
	ListNode* inserted = new ListNode;
	inserted->data = data;
	if (*head == NULL) {
		*head = inserted;
		inserted->next = *head;
	}
	else {
		ListNode* tail = *head;
		while (tail->next != *head) {
			tail = tail->next;
		}
		inserted->next = *head;
		*head = inserted;
		tail->next = *head;
	}
}

void InsertAtTail(ListNode** head, int data) {
	ListNode* inserted = new ListNode;
	inserted->data = data;
	if (*head == NULL) {
		*head = inserted;
		inserted->next = *head;
	}
	else {
		ListNode* tail = *head;
		while (tail->next != *head) {
			tail = tail->next;
		}
		tail->next = inserted;
		inserted->next = *head;
	}
}

void DeleteHeadNode(ListNode** head) {
	ListNode* removed = *head;
	if (*head == NULL) {
		return;
	}
	else {
		ListNode* tail = *head;
		while (tail->next != *head) {
			tail = tail->next;
		}
		if (tail == *head) {
			*head = NULL;
		}
		else {
			(*head) = (*head)->next;
			tail->next = *head;
		}
		delete(removed);
	}
}

void DeleteTailNode(ListNode** head) {
	if (*head == NULL) {
		return;
	}
	else {
		ListNode* tail = *head;
		ListNode* tail_prev = NULL;
		while (tail->next != *head) {
			tail_prev = tail;
			tail = tail->next;
		}
		ListNode* removed = tail;
		if (tail == *head) {
			*head = NULL;
		}
		else {
			tail_prev-> next = *head;
		}
		delete(removed);
	}
}

ListNode* head = NULL;

int main() {
	InsertAtHead(&head, 1);
	PrintList(head);
	InsertAtHead(&head, 2);
	PrintList(head);
	InsertAtHead(&head, 3);
	PrintList(head);
	InsertAtHead(&head, 4);
	PrintList(head);
	InsertAtHead(&head, 5);
	PrintList(head);
	DeleteHeadNode(&head);
	PrintList(head);
	DeleteTailNode(&head);
	PrintList(head);
	DeleteHeadNode(&head);
	PrintList(head);
	DeleteTailNode(&head);
	PrintList(head);
}
