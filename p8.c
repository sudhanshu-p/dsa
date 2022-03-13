#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf {
    int data, height;
    struct Leaf *left, *right;
} Leaf;

int heightAVL(Leaf *leaf);     

Leaf *rotateRightAVL(Leaf *leaf);
Leaf *rotateLeftAVL(Leaf *leaf);

int balanceFactor(Leaf *leaf);

Leaf *insertAVL(Leaf *leaf, int val);

void inorder (Leaf *leaf);

void main() {
    int n;
    Leaf* head = (Leaf*) malloc (sizeof(Leaf));
    printf("Enter the size of the list: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Now enter the elements: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    head->data = arr[0];
    head->left = NULL;
    head->right = NULL;
    printf("Inorder traversal of the tree: \n");
    for(int i = 1; i < n; i++) {
        head = insertAVL (head, arr[i]);
    }
    inorder(head);
}

int heightAVL (Leaf *leaf) {
    if (leaf == NULL)
        return -1;
    if (leaf->left == NULL && leaf->right == NULL)
        return 0;
    int lh = 0;
    if(leaf->left)
        lh = heightAVL(leaf->left);
    int rl = 0;
    if(leaf->right)
        heightAVL(leaf->right);

    if (lh > rl)
        return lh + 1;
    return rl + 1;
}

Leaf *rotateRightAVL(Leaf *leaf) {
    Leaf *t1;
    Leaf *t2;
    t1 = leaf->left;
    t2 = t1->right;
    t1->right = leaf;
    leaf->left = t2;
    return t1;
}

Leaf *rotateLeftAVL(Leaf *leaf) {
    Leaf *t1;
    Leaf *t2;
    t1 = leaf->right;
    t2 = t1->left;
    leaf->right = t2;
    t1->height = heightAVL(t1);
    return t1;
}

int balanceFactor(Leaf *leaf) {
    if (leaf == NULL)
        return 0;
    return heightAVL(leaf->left) - heightAVL(leaf->right);
}

Leaf *insertAVL(Leaf *leaf, int val) {
    int balance = balanceFactor(leaf);
    if (leaf == NULL) {
        Leaf *leaf = (Leaf *)malloc(sizeof(Leaf));
        leaf->data = val;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }
    else if (val < leaf->data)
        leaf->left = insertAVL(leaf->left, val);
    else if (val > leaf->data)
        leaf->right = insertAVL(leaf->right, val);
    if (balance > 1 && val < (leaf->left->data))
        return rotateRightAVL(leaf);
    if (balance < -1 && val > (leaf->right->data))
        return rotateLeftAVL(leaf);

    if (balance > 1 && (val > leaf->left->data)) {
        leaf->left = rotateLeftAVL(leaf->left);
        return rotateRightAVL(leaf);
    }
    if (balance < -1 && val < leaf->right->data) {
        leaf->right = rotateRightAVL(leaf->right);
        return rotateLeftAVL(leaf);
    }
    return leaf;
}

void inorder(Leaf *leaf) {
    if (leaf == NULL)
        return;
    inorder(leaf->left);
    printf("%d\t", leaf->data);
    inorder(leaf->right);
}