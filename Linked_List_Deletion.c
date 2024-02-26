# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    head = (struct Node *) malloc (sizeof(struct Node));
    struct Node *newnode = NULL, *temp;
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
        temp = temp->data;
    }
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes ");
    scanf("%d", &nodes);

    cretate_list(nodes);
    display();
}