// Implementation of stack using array.
# include <stdio.h>
# include <stdlib.h>
# define max 5

int stack[100], top = -1;

void push(int data) {
    top++;
    stack[top] = data;
}

void pop() {
    printf("\n%d\n", stack[top]);
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1 ---- Push");
        printf("\n2 ---- Pop");
        printf("\n3 ---- Print the top element");
        printf("\n4 ---- Print all the elements in the stack");
        printf("\n5 ---- Exit\n");

        printf("\nEnter your choice :-  ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (top >= max - 1) {
                    printf("\nStack Overflow\n");
                }
                else {
                    printf("Enter the data you want to push :-  ");
                    scanf("%d", &data);
                    push(data);
                }
                break;
            
            case 2:
                if (top == -1) {
                    printf("\nStack Underflow\n");
                }
                else {
                    pop();
                }
                break;

            case 3:
                printf("\nThe top element of the stack is %d\n", stack[top]);
                break;

            case 4:
                if (top == -1) {
                    printf("\nNo elements to display in the stack\n");
                }
                else {
                    display();
                }
                break;

            case 5:
                exit(0);
                break;
        }
    }
}