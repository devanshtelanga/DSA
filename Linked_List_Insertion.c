# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    head = (struct Node *) malloc (sizeof(struct Node));
    int data;
    struct Node *newnode, *temp;
    printf("Enter the data at Node 1:-  ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data at Node %d:-  ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void print_list() {
    struct Node *temp = NULL;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert_at_beginning() {
    int data;
    struct Node *first = NULL;
    first = (struct Node *) malloc (sizeof(struct Node));
    printf("\n\nEnter the data at Node :-  ");
    scanf("%d", &data);
    first->data = data;
    first->next = head;
    head = first;
}

void insert_at_end() {
    struct Node *new, *newnode = NULL;
    int data;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    new = head;
    printf("\nEnter the data :-  ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    
    while (new->next != NULL){
        new = new->next;
    }

    new->next = newnode;
    return;
}

void insert_in_middle() {
    int pos, data;
    printf("Enter the Position :-  ");
    scanf("%d", &pos);
    struct Node *newnode = NULL, *temp = head;
    for (int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data :-  ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;

}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    print_list();

    int choice;
    while (1) {
        printf("\n\nPress 1----- To Insert in the Beginning \n");
        printf("Press 2----- To Insert in the End \n");
        printf("Press 3----- To Insert in the Middle \n");
        printf("Press 4----- Exit \n");
        
        printf("\nEnter your choice :-  ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_at_beginning();
                print_list();
                break;
            case 2:
                insert_at_end();
                print_list();
                break;
            case 3:
                insert_in_middle();
                print_list();
                break;
            case 4:
                exit(0);
        }
    }

}