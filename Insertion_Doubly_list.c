// Insertion in Doubly Linked List
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
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
        newnode->next = NULL;
        temp = temp->next;
    }
}

void display() {
    printf("\n");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insert_at_beg() {
    struct Node *newnode = NULL;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the Data in Newnode :-  ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insert_at_end() {
    struct Node *newnode = NULL, *temp;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data in the Newnode :-  ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void insert_after_given_value() {
    int val;
    printf("Enter the data you want to search ");
    scanf("%d", &val);

    struct Node *temp = head;
    while (temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data in New node :-  ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    temp = newnode->next;
    temp->prev = newnode;
}

int main() {
    int nodes;
    printf("Enter the number of nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    insert_at_beg();
    display();
    insert_at_end();
    display();
    insert_after_given_value();
    display();
}