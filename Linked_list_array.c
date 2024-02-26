# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create_list(struct Node **head, int element) {
    struct Node *newnode = NULL, *temp;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
    }
    else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct Node *array_to_list(int array[], int size) {
    struct Node *head = NULL;
    for (int i = 0; i < size; i++) {
        create_list(&head, array[i]);
    }
    return head;  
}

void traverse(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("there are no elements in the list ");
        return;
    }
    else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    struct Node *head = array_to_list(array, 5);
    traverse(head);
}