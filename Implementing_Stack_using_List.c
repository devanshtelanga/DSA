# include <stdio.h>
# include <stdlib.h>
struct Node {
    int data;
    struct Node *next;};
int count = 0;
struct Node *top = NULL;
void push(int data) {
    struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
    newnode->next = NULL;
    newnode->data = data;
    if (top == NULL) {
        top = newnode; }
    else {
        newnode->next = top;
        top = newnode;} count++;}
void display() {
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data); temp = temp->next;}}
int isempty() {
    if (top == NULL) {
        return 1;  }
    else {
        return 0;}}
int pop() {
    int popped = top->data;
    top = top->next;
    count--;
    return popped;}
int main() { int choice, data;
    while (1) {
        printf("\nPress 1 ---- Push");
        printf("\nPress 2 ---- Pop");
        printf("\nPress 3 ---- Display");
        printf("\nPress 4 ---- Peek");
        printf("\nPress 5 ---- Exit");
        printf("\nEnter your choice :-  ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data :-  ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                if (isempty()) {  printf("\nThe Stack is Empty"); }
                else {  data = pop();  printf("\n%d", data);   }
                break;
            case 3:
                display();
                break;
            case 4: printf("The Top most element is %d", top->data);
                break;
            case 5:
                exit(0);}}}