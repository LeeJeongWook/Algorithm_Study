#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>

using namespace std;

typedef struct ListNode {
	int data;
	struct ListNode* next;
} ListNode;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int checksum;
	string str;

	while (getline(cin, str)) {
		checksum = 0;
		if (str == "#")
			break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')
				continue;
			checksum += (i + 1) * ((int)str[i] - 64);
		}
		cout << checksum << '\n';
	}

	return 0;
}
