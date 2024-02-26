// User defined doubly Linked List
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
        newnode->next = NULL;
        temp = temp->next;
    }
}

void display() {
    struct Node *temp = head, *m;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        m = temp;
        temp = temp->next;
    }
    printf("\n");
    while (m != NULL) {
        printf("%d  ", m->data);
        m = m->prev;
    }
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
}