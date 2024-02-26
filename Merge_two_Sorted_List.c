# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create_list(int nodes) {
    if (nodes == 0) {
        return NULL;
    }
    struct Node *head = (struct Node *) malloc (sizeof(struct Node));
    struct Node *newnode = NULL, *temp;
    printf("Enter the data in Node 1 :-  ");
    scanf("%d", &head->data);

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

struct Node *merge_list(struct Node *old, struct Node *new) {
    struct Node *temp1 = old, *temp2 = new;
    struct Node *head = NULL, *current, *temp;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data >= temp2->data) {
            current = temp2;
            temp2 = temp2->next;
            current->next = NULL;
            if (head == NULL) {
                head = current;
            }
            else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = current;
            }
        }
        else if (temp2->data >= temp1->data) {
            current = temp1;
            temp1 = temp1->next;
            current->next = NULL;
            if (head == NULL) {
                head = current;
            }
            else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = current;
            }
        }
    }
    if (temp1 != NULL) {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = temp1;
    }

    if (temp2 != NULL) {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = temp2;
    }

    return head;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes in List 1 :-  ");
    scanf("%d", &nodes);
    struct Node *head1 = create_list(nodes);
    printf("\nEnter the Number of Nodes in List 2 :-  ");
    scanf("%d", &nodes);
    struct Node *head2 = create_list(nodes);
    display(head1);
    display(head2);
    
    struct Node *merge = merge_list(head1, head2);

    display(merge);
}