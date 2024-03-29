// Write a program to delete a node in the beginning of the linked list.
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

void middle_del() {
    int pos;
    printf("\n\nEnter the Position you want to delete :-  ");
    scanf("%d", &pos);
    struct Node *temp = NULL, *del;
    temp = head;
    for (int i = 2; i < pos; i++) {
        temp = temp->next;
    }  
    del = temp->next;
    temp->next = del->next;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    middle_del();
    printf("\n\n\n");
    display();
}