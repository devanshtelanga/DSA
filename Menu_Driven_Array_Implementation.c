# include <stdio.h>
# include <stdlib.h>
char tree[10];
void root() {
    if (tree[0] != '\0') {
        printf("\nThe Root of the tree already exists\n");
        return;
    }
    char key;
    printf("\nEnter the character you want to Insert :-  ");
    scanf(" %c", &key);
    tree[0] = key;
}
void display() {
    for (int i = 0; i < 10; i++) {
        if (tree[i] != '\0') {
            printf("%c ", tree[i]);
        }
        else {
            printf("- ");
        }
    }
}
void left_child() {
    int parent;
    printf("\nEnter the Index of the Parent Node :-  ");
    scanf("%d", &parent);
    if (tree[parent] == '\0') {
        printf("\nCannot set child at %d\n", (parent * 2) + 1);
        return;
    }
    if (tree[(parent * 2) + 1] != '\0') {
        printf("\nLeft Child of %c already exists\n", tree[parent]);
        return;
    }
    else {
        char key;
        printf("\nEnter the character you want to Insert :-  ");
        scanf(" %c", &key);
        tree[(parent * 2) + 1] = key;
    }
}
void right_child() {
    int parent;
    printf("\nEnter the Index of the Parent Node :-  ");
    scanf("%d", &parent);
    if (tree[parent] == '\0') {
        printf("\nCannot set child at %d\n", (parent * 2) + 2);
        return;
    }
    if (tree[(parent * 2) + 2] != '\0') {
        printf("\nRight Child of %c already exists\n", tree[parent]);
        return;
    }
    else {
        char key;
        printf("\nEnter the character you want to Insert :-  ");
        scanf(" %c", &key);
        tree[(parent * 2) + 2] = key;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nPress 1 --- To Create the Root ");
        printf("\nPress 2 --- To Create the Left Child ");
        printf("\nPress 3 --- To Create the Right Child ");
        printf("\nPress 4 --- Display ");
        printf("\nPress 5 --- Exit ");

        printf("\n\nEnter you choice :-  ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                root();
                break;
            
            case 2:
                left_child();
                break;

            case 3:
                right_child();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
        }
    }
}