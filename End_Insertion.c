// Write a program to insert a newnode at the end of the linked list.
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    int data;
    struct Node *newnode = NULL, *temp;
    head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data you want to insert ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data you want to insert ");
        scanf("%d", &data);
        newnode->data = data;
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

void insert_at_end() {
    int data;
    struct Node *temp, *newnode = NULL;
    temp = head;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data you want to insert ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    insert_at_end();
    display();
}