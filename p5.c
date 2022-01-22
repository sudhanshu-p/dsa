// Create a self-referential structure, Node to represent a node of a singly linked linear list.
// Implement the routines to (1) find length of the list, (2) create a list, (3) insert an element
// – at the beginning, at the end and at a specified position in the list, insertion in ordered way (4) delete an element
// from the beginning, end or a specified position at the list, (5) reverse the list, (6) search the
// list, (7) Sort the list. Create a menu-driven program to test these routines.
// Use the singly linked linear list routines to implement a linked stack and a linked queue.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int lengthOfList (Node* node);
void traverse (Node* node);

void insertAtStart (Node** head, int data);
void insertAtPos (Node* node, int data, int loc);
void insertAtEnd (Node* node, int data);

void deleteStart (Node** head, Node* node);
void deleteAtPos (Node* node, int loc);
void deleteEnd (Node* node);

int search (Node* node, int data);
void reverse (Node** head);
void sortList (Node** head);

int linkedPeek (Node* head);

void main() {
	int c1, c2, c3, c4, t1, t2;
	Node* head = NULL;
	while(1) {
		printf("Enter the type of linked structure you want to use:\n1: Linked list\n2: Linked Stack\n3: Linked Queue\n4: Exit\nYour Choice: ");
		scanf("%d", &c1);
		switch(c1) {
			case 1: 
				printf("You chose Linked List\n");
				while(1) {
					printf("\n----------------\nNow select the operation you want to perform: \n1: Find the length of the list\n2: Insert an element in the list\n3: Delete an element from the list\n4: Reverse the list\n5: Search for an element in the list\n6: Sort the list\n7: Print the list\nYour Choice: ");
					scanf("%d", &c2);
					if(c2 == -1)
						break;
					switch(c2) {
						case 1: 
							t1 = lengthOfList(head);
							printf("Length of the linked list is: %d\n", t1);
							break;
						case 2: 
							printf("You chose to insert an element.\n");
							printf("Enter the element you want to insert: ");
							scanf("%d", &t1);
							printf("Select where you want to insert:\n1: At the beginning\n2: At a specific position\n3: At the end\nYour Choice: ");
							scanf("%d", &c3);
							switch(c3) {
								case 1: 
									printf("Inserting %d at the beginning\n", t1);
									insertAtStart (&head, t1);
									break;
								case 2: 
									printf("Enter the position where you want to insert: ");
									scanf("%d", &t2);
									printf("Inserting %d at the %d position.\n", t1, t2);
									insertAtPos(head, t1, t2);
									break;
								case 3: 
									printf("Inserting %d at the end.\n", t1);
									insertAtEnd(head, t1);
									break;
								default: 
									printf("Invalid Choice.\n");
									break;
							}
							break;
						case 3: 
							printf("You chose to delete an element.\n");
							printf("Enter from where you want to delete:\n1: At the start\n2: At a specific position\n3: At the end\nYour Choice: ");
							scanf("%d", &c3);
							switch(c3) {
								case 1: 
									printf("Deleting the 1st element\n");
									deleteStart(&head, head);
									break;
								case 2: 
									printf("Enter the position of the element you want to delete: ");
									scanf("%d", &t1);
									deleteAtPos(head, t1);
									break;
								case 3: 
									printf("Deleting the last element\n");
									deleteEnd(head);
									break;
								default:
									printf("Invalid Choice.\n");
									break;
							}
							break;
						case 4: 
							printf("You chose to reverse the list.\n");
							reverse(&head);
							printf("List reversed.\n");
							break;
						case 5: 
							printf("You chose to search an element\n");
							printf("Enter the element you want to search: ");
							scanf("%d", &t1);
							t2 = search(head, t1);
							if(t2 == -1) {
								printf("Element not found\n");
								break;
							}
							printf("Element %d found at location: %d\n", t1, t2 + 1);
							break;
						case 6: 
							printf("You chose to sort the list.\n");
							sortList(&head);
							printf("List sorted.\n");
							break;
						case 7: 
							traverse (head);
							break;
						default: 
							printf("Invalid Choice\n");
							break;
					}
				}
				printf("Would you like to retain the element in the list? (0 for no, 1 for yes)\n");
				scanf("%d", &c4);
				if(c4 == 0)
					head = NULL;
				break;
			case 2: 
				printf("You chose Linked Stack\n");
				while(1) {
					printf("\n----------------\nEnter which functionality you'd like to use: \n1: Push\n2: Pop\n3: Check Top Value\n4: Print the entire Stack\n-1: go back to the data structure selection\nYour Choice: ");				
					scanf("%d", &c2);
					if(c2 == -1) 
						break;
					switch(c2) {
						case 1:
							printf("Enter the element you want to push: \n");
							scanf("%d", &t1);
							if(head == NULL)
								insertAtStart(&head, t1);
							else
								insertAtEnd(head, t1);
							break;
						case 2:
							printf("You Chose to Pop an element.\n");
							deleteEnd(head);
							break;
						case 3:
							t1 = linkedPeek(head);
							if(t1 != -1)
								printf("The top value is: %d", t1);
							break;
						case 4: 
							printf("You chose to print the stack.\n");
							traverse(head);
							break;
						default:
							printf("Invalid Choice.\n");
							break;
					}
				}
				scanf("%d", &c4);
				printf("Would you like to retain the element in the list? (0 for no, 1 for yes)\n");
				if(c4 == 0)
					head = NULL;
				break;
			case 3:
				printf("You chose Linked Queue\n");
				while(1) {
					printf("\n----------------\nEnter which functionality you'd like to use: \n1: Enqueue\n2: Dequeue\n3: Display Queue\n-1: go back to the data structure selection\nYour Choice: ");
					scanf("%d", &c2);
					if(c2 == -1) 
						break;
					switch(c2) {
						case 1: 
							printf("Enter the element you want to enqueue\n");
							scanf("%d", &t1);
							if(head == NULL)
								insertAtStart(&head, t1);
							else
								insertAtEnd(head, t1);
							break;
						case 2: 
							printf("You chose Dequeue\n");
							deleteStart(&head, head);
							break;
						case 3: 
							printf("You chose to print the queue.\n");
							traverse(head);
							break;
						default:
							printf("Invalid Choice.\n");
					}
				}
				printf("Would you like to retain the element in the list? (0 for no, 1 for yes)\n");
				scanf("%d", &c4);
				if(c4 == 0)
					head = NULL;
				break;
			case 4: 
				printf("Ending program.\n");
				exit(0);
			default:
				printf("Invalid Choice.\n");
				break;
		}
	}
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
	printf("The linked list is: ");
	while(node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void insertAtStart (Node** head, int data) {
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
	printf("Insertion successfull\n");
}

void insertAtPos(Node* node, int data, int loc) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	Node* prev;
	prev = node;
	newNode->data = data;
	int count = 0;
	while(count != loc && node != NULL) {
		prev = node;
		node = node->next;
		count++;
	}
	if(node == NULL) {
		printf("Cannot insert.\n");
		return;
	}
	prev->next = newNode;
	newNode->next = node;
	printf("Insertion successfull\n");
	return;
}

void insertAtEnd(Node* node, int data) {
	if(node == NULL) {
		node->data = data;
		return;
	}
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	while(node->next != NULL) {
		node = node->next;
	}
	node->next = newNode;
}

void deleteStart (Node** head, Node* node) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	*head = node->next;
}

void deleteAtPos(Node* node, int loc) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	Node* prev;
	int count = 0;
	while(count!= loc && node != NULL) {
		prev = node;
		node = node->next;
		count ++;
	}
	if(node == NULL) {
		printf("Can't delete an element that doesn't exist\n");
		return;
	}
	prev->next = node->next;
}

void deleteEnd (Node* node) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	Node* prev;
	while(node->next != NULL) {
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
}

int search(Node* node, int data) {
	int count = 0;
	while(node != NULL) {
		if(node->data == data)
			return count;
		count++;
		node = node->next;
	}
	return -1;
}

void reverse(Node** head) {
	Node* prev = NULL;
	Node* next = NULL;
	Node* curr = *head;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void sortList(Node** head) {
	Node* nodeI = *head;
	while(nodeI != NULL) {
		Node* nodeJ = nodeI;
		int least = nodeJ->data;
		int leastIndex = 0;
		int count = 1;
		nodeJ = nodeJ->next;
		while(nodeJ != NULL) {
			if(nodeJ->data < least) {
				leastIndex = count;
				least = nodeJ->data;
			}
			count++;
			nodeJ = nodeJ->next;
		}
		if(leastIndex != 0) {
			Node* nodeK = nodeI;
			while(leastIndex > 0) {
				nodeK = nodeK->next;
				leastIndex--;
			}
			int temp = nodeK->data;
			nodeK->data = nodeI->data;
			nodeI->data = temp;
		}
		nodeI = nodeI->next;
	}
}

int linkedPeek (Node* node) {
	if(node == NULL){
		printf("The list is Empty!\n");
		return -1;
	}
	while(node->next!= NULL) 
		node = node->next;
	return node->data;
}	