#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtRight(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->right != NULL) {
        current = current->right;
    }

    current->right = newNode;
    newNode->left = current;
}

// Function to delete a node with a specific key
void deleteNode(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = *head;
    while (current != NULL && current->data != key) {
        current = current->right;
    }

    if (current == NULL) {
        printf("Key not found. Cannot delete.\n");
        return;
    }

    if (current->left != NULL) {
        current->left->right = current->right;
    } else {
        *head = current->right;
    }

    if (current->right != NULL) {
        current->right->left = current->left;
    }

    free(current);
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->right;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, key, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                insertAtRight(&head, data);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                printf("Linked list contents:\n");
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
