#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
} heap_t;

// Function to swap two nodes
void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the heap rooted at index i
void maxHeapify(Node *node) {
    Node *largest = node;
    Node *left = node->left;
    Node *right = node->right;

    if (left != NULL && left->data > largest->data) {
        largest = left;
    }

    if (right != NULL && right->data > largest->data) {
        largest = right;
    }

    if (largest != node) {
        swapNodes(&node, &largest);
        maxHeapify(largest);
    }
}

// Function to extract the root node from the heap
int heap_extract(heap_t **root) {
    if (*root == NULL || (*root)->root == NULL) {
        return 0; // Heap is empty or invalid
    }

    Node *heapRoot = (*root)->root;
    int extractedValue = heapRoot->data;

    // Find the last level-order node
    Node *lastNode = heapRoot;
    Node *parentOfLastNode = NULL;
    while (lastNode->left != NULL) {
        parentOfLastNode = lastNode;
        lastNode = lastNode->left;
        if (lastNode->right != NULL) {
            parentOfLastNode = lastNode;
            lastNode = lastNode->right;
        }
    }

    if (parentOfLastNode != NULL) {
        if (parentOfLastNode->right != NULL) {
            parentOfLastNode->right = NULL;
        } else {
            parentOfLastNode->left = NULL;
        }
    } else {
        (*root)->root = NULL;
    }

    if (lastNode != heapRoot) {
        heapRoot->data = lastNode->data;
    }

    free(lastNode);

    if ((*root)->root != NULL) {
        maxHeapify((*root)->root);
    }

    return extractedValue;
}

int main() {
    // Example usage
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->root = (Node *)malloc(sizeof(Node));
    heap->root->data = 10;

    int extractedValue = heap_extract(&heap);
    printf("Extracted Value: %d\n", extractedValue);

    // Free the heap and its nodes (you might want to implement a proper freeing function)
    free(heap->root);
    free(heap);

    return 0;
}
