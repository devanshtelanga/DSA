# include <stdio.h>
# include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *front = NULL, *rear = NULL;

void insert() {
    struct Queue *newnode = (struct Queue *) malloc (sizeof(struct Queue));
    printf("\nEnter the value you want to insert :-  ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

int isempty() {
    if (front == NULL || rear == NULL) {
        return 1;
    }
    return 0;
}

int delete() {
    int value = front->data;
    struct Queue *temp = front;
    front = front->next;
    free(temp);
    return value;
}

void display() {
    printf("\n");
    struct Queue *temp = front;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nPress 1 ---- Insert an element");
        printf("\nPress 2 ---- Delete an element");
        printf("\nPress 3 ---- Display the queue");
        printf("\nPress 4 ---- Display the Front element");
        printf("\nPress 5 ---- Display the Rear element");
        printf("\nPress 6 ---- Exit");

        printf("\n\nEnter the choice :-  ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;
            
            case 2:
                if (isempty()) {
                    printf("\nUnderflow Condition\n");
                }
                else {
                    printf("\n%d \n", delete());
                }
                break;
            
            case 3:
                display();
                break;
            case 4:
                printf("\nThe front element is %d\n", front->data);
                break;
            case 5:
                printf("\nThe Rear element is %d\n", rear->data);
                break;
            case 6:
                exit(0);}}}