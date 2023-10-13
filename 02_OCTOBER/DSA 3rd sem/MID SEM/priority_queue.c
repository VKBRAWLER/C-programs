#include <stdio.h>
#include <stdlib.h>

// Define a struct for each node in the linked list
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Define a struct for the priority queue itself
typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

// Define a function to insert an element into the priority queue
void insert(PriorityQueue* pq, int data, int priority) {
    // Create a new node with the given data and priority
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    // If the priority queue is empty, set the new node as the head
    if (pq->head == NULL) {
        pq->head = new_node;
        return;
    }

    // Traverse the linked list to find the correct position to insert the new node
    Node* curr_node = pq->head;
    Node* prev_node = NULL;
    while (curr_node != NULL && curr_node->priority >= priority) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // Insert the new node into the linked list
    if (prev_node == NULL) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

// Define a function to remove the element with the highest priority from the priority queue
int remove_max(PriorityQueue* pq) {
    // If the priority queue is empty, return -1
    if (pq->head == NULL) {
        return -1;
    }

    // Remove the node with the highest priority from the linked list
    Node* max_node = pq->head;
    pq->head = pq->head->next;
    int max_data = max_node->data;
    free(max_node);

    // Return the value of the removed element
    return max_data;
}

// Define a function to print the elements of the priority queue in order of priority
void print_priority_queue(PriorityQueue* pq) {
    // Traverse the linked list and print each element in order of priority
    Node* curr_node = pq->head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    // Create a new priority queue
    PriorityQueue pq = {NULL};

    // Insert some elements into the priority queue
    insert(&pq, 5, 2);
    insert(&pq, 3, 1);
    insert(&pq, 7, 3);
    insert(&pq, 1, 1);

    // Print the elements of the priority queue in order of priority
    print_priority_queue(&pq);

    // Remove the element with the highest priority from the priority queue
    int max_data = remove_max(&pq);
    printf("Removed element with highest priority: %d\n", max_data);

    // Print the elements of the priority queue in order of priority
    print_priority_queue(&pq);

    return 0;
}