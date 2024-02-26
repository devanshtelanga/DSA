// Write a program to insert a node before the given value by the user,
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    struct Node *newnode = NULL, *temp;
    head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data in Node 1 :-  ");
    scanf("%d", &head->data);
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insert_before_node(int value) {
    int target;
    printf("Enter the Number before which you want to insert :-  ");
    scanf("%d", &target);

    struct Node *before, *after;
    before = head, after = head->next;

    if (head->data == target) {
        struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
        newnode->data = value;
        newnode->next = head;
        head = newnode;
        return;
    }

    while (after->data != target) {
        after = after->next;
        before = before->next;
    }
    struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
    newnode->data = value;
    newnode->next = after;
    before->next = newnode;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :- ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    insert_before_node(15);
    display();
}