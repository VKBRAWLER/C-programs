#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set the data for the new node
    new_node->data = new_data;
    // Set the previous pointer of the new node to NULL
    new_node->prev = NULL;
    // Set the next pointer of the new node to the current head of the list
    new_node->next = (*head_ref);
    // If the list is not empty, set the previous pointer of the current head to the new node
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    // Set the head of the list to the new node
    (*head_ref) = new_node;
}

// Function to delete a node from the list
void deleteNode(struct Node** head_ref, struct Node* del_node) {
    // If the node to be deleted is the head of the list, set the head to the next node
    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }
    // If the node to be deleted is not the last node, set the next node's previous pointer to the previous node
    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }
    // If the node to be deleted is not the first node, set the previous node's next pointer to the next node
    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }
    // Free the memory allocated for the node to be deleted
    free(del_node);
}

int main() {
    // Initialize the head of the list to NULL
    struct Node* head = NULL;
    // Prompt the user to input data for each node and insert it at the beginning of the list
    for (int i = 0; i < 7; i++) {
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }
    // Print the list
    printf("Doubly linked list:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    // Delete the second node from the list
    deleteNode(&head, head->next);
    // Print the list again
    printf("Doubly linked list after deleting second node:\n");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}
