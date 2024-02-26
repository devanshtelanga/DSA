// WAP to insert a Node in the linked list which is in an sorted order and on inserting the order should not be changed.
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
        temp->next = newnode;
        newnode->next = NULL;
        temp = temp->next;
    }}
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
void sort() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *help = head;
        while (help != NULL) {
            if (temp->data < help->data) {
                int value = temp->data;
                temp->data = help->data;
                help->data = value;
            }
            help = help->next;
        } 
        temp = temp->next;
    }
}

void insert() {
    struct Node *newnode = NULL;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data in the Newnode :-  ");
    scanf("%d", &newnode->data);
    if (newnode->data < head->data) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct Node *prev = head, *after = head->next;
    while (after != NULL) {
        if (prev->data < newnode->data && after->data < newnode->data) {
            prev = prev->next;
            after = after->next;
        }
        else {
            break;
        }
    }
    prev->next = newnode;
    newnode->next = after;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    sort();
    display();
    insert();
    display();
}