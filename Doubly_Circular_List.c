// Creation of User defined Doubly Circular Linked
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void create_list(int nodes) {
    struct Node *newnode = NULL, *temp;
    head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data in Node 1 :-  ");
    scanf("%d", &head->data);

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}

void display() {
    struct Node *temp = head, *ok;
    do {
        printf("%d  ", temp->data);
        ok = temp;
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    do {
        printf("%d  ", ok->data);
        ok = ok->prev;
    } while (ok != head->prev);
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
}