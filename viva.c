#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

void createHead (Node** head, int val) {
	Node* tempNode = (Node*) malloc (sizeof(Node));
	tempNode->data = val;
	tempNode->next = NULL;
	*head = tempNode;
}

void insert(Node* node, int val) {
	Node* tempNode = (Node*) malloc (sizeof(Node));
	tempNode->data = val;
	tempNode->next = NULL;
	while(node->next != NULL) {
		node = node->next;
	}
	node->next = tempNode;
}

int getElement (Node* node, int loc) {
	int count = 0;
	while(count != loc) {
		node = node->next;
		count++;
	}
	return node->data;
}

int lengthOfList (Node* node) {
	int count = 0;
	if(node == NULL)
		return 0;
	while(node != NULL) {
		node = node-> next;
		count++;
	}
	return count;
}

void traverse (Node* node) {
	while(node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void main() {
	int n, temp;
	printf("Enter the number of elements in the linked list: ");
	scanf("%d", &n);
	Node* head = (Node*) malloc (sizeof(Node));
	printf("Enter head node: ");
	scanf("%d", &head->data);
	head->next = NULL;
	n--;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		insert(head, temp);
	}
	printf("The linked list is: ");
	traverse(head);
	Node* oddList = NULL;
	Node* evenList = NULL;
	for(int i = 0; i <= n; i++) {
		int t = getElement (head, i);
		if(t % 2 == 1) {
			if(lengthOfList(oddList) > 0)
				insert(oddList, t);
			else
				createHead(&oddList, t);
		}
		else {
			if(lengthOfList(evenList) > 0)
				insert(evenList, t);
			else
				createHead(&evenList, t);
		}
	}
	printf("Odd List: ");
	traverse(oddList);
	printf("Even List: ");
	traverse(evenList);
}