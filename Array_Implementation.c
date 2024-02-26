# include <stdio.h>

char tree[10];

void root(char key) {
    if (tree[0] != '\0') {   // '\0' is the Null Character.
        printf("\nThe Root of the tree already exists\n");
    }
    else {
        tree[0] = key;
    }
}

void leftchild(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("\nCannot set child at %d\n", (parent * 2) + 1);
    }
    else {
        tree[(parent * 2) + 1] = key;
    }
}

void rightchild(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("\nCannot set child at %d\n", (parent * 2) + 2);
    }
    else {
        tree[(parent * 2) + 2] = key;
    }
}

void display() {
    printf("\n");
    for (int i = 0; i <= 10; i++) {
        if (tree[i] != '\0') {
            printf("%c ", tree[i]);
        }
        else {
            printf("%c ", '-');
        }
    }
}

int main() {
    root('A'); // 0
    leftchild('B', 0); // 1
    rightchild('C', 0); // 2
    leftchild('D', 1); // 0 3
    leftchild('E', 3); // 4
    display();
}