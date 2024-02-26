# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create_Node(int data) {
    struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node *root = NULL;
    root = create_Node(10);
    root->left = create_Node(20);
    root->right = create_Node(30);
    root->left->left = create_Node(40);
    preorder(root);
}