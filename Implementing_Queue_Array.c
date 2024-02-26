# include <stdio.h>
# include <stdlib.h>
# define max 3
int front = -1, rear = -1, queue[max];
int isfull() {
    if (rear == max - 1) {
        return 1;
    }
    return 0;
}
int isempty() {
    if ((front == -1 && rear == -1) || front > rear) {
        return 1;
    }
    return 0;
}
void insert() {
    int value;
    printf("\nEnter the Value you want to insert :-  ");
    scanf("%d", &value);
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = value;
}
int delete() {
    int value = queue[front];
    front++;
    return value;
}
int main() {
    int choice;
    while (1) {
        printf("\nPress 1 ---- Insert an element");
        printf("\nPress 2 ---- Delete an element");
        printf("\nPress 3 ---- Display the queue");
        printf("\nPress 4 ---- Display Front and the element");
        printf("\nPress 5 ---- Display rear and the element");
        printf("\nPress 6 ---- Exit");

        printf("\n\nEnter the choice :-  ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (isfull()) {
                    printf("\nOverflow Condition\n");
                }
                else {
                    insert();
                }
                break;
            
            case 2:
                if (front > rear) {
                    front = -1;
                    rear = -1;
                }
                else if (isempty()) {
                    printf("\nUnderflow Condition\n");
                }
                else {
                    printf("\n%d", delete());
                }
                break;
            
            case 3:
                printf("\n");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                break;

            case 4:
                printf("\nValue of front is %d and the element is %d\n", front, queue[front]);
                break;

            case 5:
                printf("\nValue of rear is %d and the element is %d\n", rear, queue[rear]);
                break;

            case 6:
                exit(0);
        }
    }
}