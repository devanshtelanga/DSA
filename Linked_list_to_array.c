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
    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = NULL;
}
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int *array(int nodes) {
    struct Node *temp = head;
    int *arr;
    arr = (int *) malloc (nodes * sizeof(int));
    for (int i = 0; i < nodes; i++) {
        if (temp != NULL) {
            // printf("%d  ", temp->data);
            arr[i] = temp->data;
            temp = temp->next;
        }
        else {
            break;
        }
    }
    return arr;
}
int main() {
    int nodes;
    printf("Enter the Number of Nodes ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    printf("\n");
    int *arr = array(nodes);
    for (int i = 0; i < nodes; i++) {
        printf("%d  ", arr[i]);
    }
}