# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int idx = 0;

struct Node *create_list(struct Node *root, int size, int array[]) {
    if (idx == size) {
        return root;
    }
    if (array[idx] == -1) {
        return NULL;
    }
    root = (struct Node *) malloc (sizeof(struct Node));
    root->data = array[idx];
    idx++;
    root->left = create_list(root->left, size, array);
    root->right = create_list(root->right, size, array);
}

void Preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    Preorder(root->left);
    printf("%d ", root->data);
    Preorder(root->right);
}

int main() {
    int array[] = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1};
    int size = sizeof(array) / sizeof(array[0]);
    struct Node *root = create_list(NULL, size, array);
    Preorder(root);
}