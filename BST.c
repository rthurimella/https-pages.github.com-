#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
int insert(struct Node** root, int x) {
    if (*root == NULL) {
        *root = createNode(x);
        return 1;  // Inserted successfully
    } else if (x == (*root)->data) {
        return 0;  // Value already exists
    } else if (x < (*root)->data) {
        return insert(&((*root)->left), x);
    } else {
        return insert(&((*root)->right), x);
    }
}