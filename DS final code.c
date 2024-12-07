#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* Insert(struct Node *root, int data) {
    if (root == NULL) {
        root = CreateNode(data);
    } else if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* Search(struct Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } else if (key < root->data) {
        return Search(root->left, key);
    } else {
        return Search(root->right, key);
    }
}

// Function for in-order traversal
void InOrder(struct Node *root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

// Main function to test the above implementation
int main() {
    struct Node *root = NULL;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 70);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 60);
    Insert(root, 80);

    printf("In-order traversal: ");
    InOrder(root);
    printf("\n");

    int key = 40;
    struct Node *searchResult = Search(root, key);
    if (searchResult != NULL) {
        printf("Found: %d\n", searchResult->data);
    } else {
        printf("Not Found\n");
    }

    return 0;
}

