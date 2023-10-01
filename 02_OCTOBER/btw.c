#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void addNodeInBetween(Node** head, int key, int newData) {
    Node* newNode = createNode(newData);
    Node* current = *head;

    while (current != NULL) {
            if (current->data == key) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("Key not found in the linked list.\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key, newData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append a node\n");
        printf("2. Display linked list\n");
        printf("3. Add a node in between\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                printf("Linked List: ");
                display(head);
                break;
            case 3:
                printf("Enter the key after which to add a new node: ");
                scanf("%d", &key);
                printf("Enter the data for the new node: ");
                scanf("%d", &newData);
                addNodeInBetween(&head, key, newData);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
