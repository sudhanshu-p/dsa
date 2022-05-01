#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf {
	int data;
	struct Leaf* left, *right;
} Leaf;

int heightAVL (Leaf* leaf);

void rotateRightAVL(Leaf* leaf);
void rotateLeftAVL(Leaf* leaf);

int balanceFactor (Leaf* leaf);

void insertAVL (Leaf** root, Leaf* leaf, int val);

void deletionAVL (Leaf** root, Leaf* leaf, int val);

void inorder (Leaf* leaf);
void preorder (Leaf* leaf);
void postorder (Leaf* leaf);

int searchAVL (Leaf* leaf, int val);

void parentsAVL (Leaf* leaf);
void leavesAVL (Leaf* leaf);

void main() {
	int c1, c2, temp;
	Leaf* root = NULL, *tempNode = NULL;
	while(1) {
		printf("Enter your choice: \n1: Insertion\n2: Deletion\n3: Find height\n4: Traversal\n5: Print the parent and leaf nodes\n6: Search\n-1: Exit\nYour choice: ");
		scanf("%d", &c1);
		if(c1 == -1)
			break;
		switch (c1) {
			case 1: 
				printf ("Enter the value you want to insert: ");
				scanf ("%d", &temp);
				insertAVL (&root, root, temp);
				break;
			case 2: 
				printf("Enter the value you want to delete: ");
				scanf("%d", &temp);
				deletionAVL (&root, root, temp);
				break;
			case 3: 
				printf("Height of the tree is: ", heightAVL(root));
				break;
			case 4: 
				printf("Enter how you want to traverse:\n1: Inorder]n2: Preorder\n3: Postorder\n -1: Back\nYour Choice: ");
				scanf("%d", &c2);
				if(c2 == -1)
					break;
				switch (c2) {
					case 1: 
						printf("Inorder Traversal: ");
						inorder (root);
						break;
					case 2: 
						printf("Preorder Traversal: ");
						preorder (root);
						break;
					case 3: 
						printf("Postorder Traversal: ");
						postorder (root);
						break;
					default: 
						printf("Invalid Choice.\n");
				}
				break;
			case 5: 
				printf("Parent Nodes: ");
				parentsAVL (root);
				printf("\nLeaf Nodes: ");
				leavesAVL (root);
				break;
			case 6: 
				printf("Enter the element you want to search: ");
				scanf("%d", &temp);
				c2 = searchAVL (root, temp);
				if(c2 == -1)
					printf("Element not found!\n");
				else
					printf("Element found at index: %d\n", c2);
				break;
			default:
				printf("Invalid Choice. Try again.\n");
		}
	}
	printf("Goodbye.\n");
}

int heightAVL (Leaf* leaf) {
	if(leaf == NULL)
		return -1;
	int lh = heightAVL (leaf->left);
	int rh = heightAVL (leaf->right);
	if(lh > rh)
		return lh + 1;
	return rh + 1;
}

int balanceFactor (Leaf* leaf) {
	if(leaf == NULL)
		return 0;
	return heightAVL (leaf->left) - heightAVL (leaf->right);
}

void rotateRightAVL ()

void insertAVL (Leaf** root, Leaf* leaf, int val) {
	int bf = balanceFactor (leaf);
	if(leaf == NULL) {
		Leaf* temp = (Leaf*) malloc (sizeof(Leaf));
		temp->data = val;
		temp->right = NULL;
		temp->left = NULL;
		*root = temp;
		return;
	}
	if (val < leaf->data)
		insertAVL (&leaf->left, leaf->left, val);
	else if (val > leaf->data)
		insertAVL (&leaf->right, leaf->right, val);
	else {
		printf("Node already exists!\n");
		return;
	}
	if (bf > 1 && val < leaf->left->data)
		rotateRightAVL (leaf);
	else if (bf < -1 && val > leaf->right->data)
		rotateLeftAVL (leaf);
	else if (bf > 1) {
		rotateLeftAVL (leaf->left);
		rotateRightAVL (leaf);
	}
	else if(bf){
		rotateRightAVL (leaf->right);
		rotateLeftAVL (leaf);
	}
}

