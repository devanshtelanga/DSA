// Write a program to insert another linked list in the existing linked list at some specific index.
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create_list(int nodes) {
    if (nodes == 0) {
        return NULL;
    }
    struct Node *head = (struct Node *) malloc (sizeof(struct Node));
    struct Node *newnode, *temp;
    printf("Enter the data in Node 1 :-  ");
    scanf("%d", &head->data);
    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(struct Node *head, struct Node *new_head, int nodes) {
    int pos;
    printf("Enter the position you want to insert :-  ");
    scanf("%d", &pos);

    if (pos > nodes) {
        printf("Position is more than the size of List");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = new_head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    head = temp->next;
    
    temp->next = new_head;
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = head;
    return;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    struct Node *head = create_list(nodes);
    display(head);
    struct Node *new_head = create_list(nodes);
    display(new_head);
    insert(head, new_head, nodes);
    display(head);
}