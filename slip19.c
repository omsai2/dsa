#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Doubly linked list structure
struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to initialize a doubly linked list
void initializeList(struct DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node with the given data in an ordered manner
void insertOrdered(struct DoublyLinkedList* list, int data, int ascending) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        // List is empty, insert as the first node
        list->head = newNode;
        list->tail = newNode;
    } else {
        struct Node* current = list->head;

        if (ascending) {
            // Insert in ascending order
            while (current != NULL && current->data < data) {
                current = current->next;
            }
        } else {
            // Insert in descending order
            while (current != NULL && current->data > data) {
                current = current->next;
            }
        }

        if (current == NULL) {
            // Insert at the end
            newNode->prev = list->tail;
            list->tail->next = newNode;
            list->tail = newNode;
        } else {
            // Insert before the current node
            newNode->next = current;
            newNode->prev = current->prev;

            if (current->prev == NULL) {
                // Insert at the beginning
                list->head = newNode;
            } else {
                current->prev->next = newNode;
            }

            current->prev = newNode;
        }
    }
}

// Function to search for an element in the list
struct Node* search(struct DoublyLinkedList* list, int data, int ascending) {
    struct Node* current = (ascending) ? list->head : list->tail;

    while (current != NULL) {
        if (current->data == data) {
            return current; // Element found
        }

        if (ascending) {
            current = (current->data < data) ? current->next : NULL;
        } else {
            current = (current->data > data) ? current->prev : NULL;
        }
    }

    return NULL; // Element not found
}

// Function to display the elements of the list
void displayList(struct DoublyLinkedList* list, int ascending) {
    struct Node* current = (ascending) ? list->head : list->tail;

    printf("List in %s order: ", (ascending) ? "ascending" : "descending");

    while (current != NULL) {
        printf("%d ", current->data);
        current = (ascending) ? current->next : current->prev;
    }

    printf("\n");
}

// Function to free the memory allocated for the list
void freeList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

int main() {
    struct DoublyLinkedList list;
    initializeList(&list);

    int choice, data;

    printf("Choose the order of the list:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    int ascending = (choice == 1);

    // Insert elements into the ordered list
    printf("Enter integers to insert into the list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertOrdered(&list, data, ascending);
    }

    // Display the ordered list
    displayList(&list, ascending);

    // Search for an element in the list
    printf("Enter an integer to search in the list: ");
    scanf("%d", &data);

    struct Node* searchResult = search(&list, data, ascending);
    if (searchResult != NULL) {
        printf("Element %d found in the list.\n", data);
    } else {
        printf("Element %d not found in the list.\n", data);
    }

    // Free the memory allocated for the list
    freeList(&list);

    return 0;
}

