#include <stdio.h>
#include <stdlib.h>

typedef struct HeapNode {
    int data;
    struct HeapNode* left;
    struct HeapNode* right;
} heap_t;

void max_heapify(heap_t* root) {
    heap_t* largest = root;
    heap_t* left = root->left;
    heap_t* right = root->right;

    if (left != NULL && left->data > largest->data) {
        largest = left;
    }

    if (right != NULL && right->data > largest->data) {
        largest = right;
    }

    if (largest != root) {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;
        max_heapify(largest);
    }
}

int extract_max(heap_t** root) {
    if (*root == NULL) {
        return -1; // Assuming -1 represents an error or empty heap
    }

    int max_value = (*root)->data;

    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return max_value;
    }

    if ((*root)->left == NULL || (*root)->right == NULL) {
        heap_t* temp = *root;
        *root = ((*root)->left != NULL) ? (*root)->left : (*root)->right;
        free(temp);
    } else {
        if ((*root)->left->data > (*root)->right->data) {
            (*root)->data = (*root)->left->data;
            extract_max(&(*root)->left);
        } else {
            (*root)->data = (*root)->right->data;
            extract_max(&(*root)->right);
        }
    }

    max_heapify(*root);
    return max_value;
}

int *heap_to_sorted_array(heap_t *heap, size_t *size) {
    if (heap == NULL) {
        *size = 0;
        return NULL;
    }

    // First, extract all elements from the heap
    int *sorted_array = (int *)malloc(sizeof(int));
    if (sorted_array == NULL) {
        *size = 0;
        return NULL;
    }
    *size = 0;

    int value;
    while ((value = extract_max(&heap)) != -1) {
        (*size)++;
        sorted_array = (int *)realloc(sorted_array, (*size) * sizeof(int));
        if (sorted_array == NULL) {
            *size = 0;
            return NULL;
        }
        sorted_array[(*size) - 1] = value;
    }

    return sorted_array;
}

int main() {
    // Example usage
    heap_t* root = (heap_t*)malloc(sizeof(heap_t));
    root->data = 8;
    root->left = (heap_t*)malloc(sizeof(heap_t));
    root->left->data = 6;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (heap_t*)malloc(sizeof(heap_t));
    root->right->data = 5;
    root->right->left = NULL;
    root->right->right = NULL;

    size_t size;
    int* sorted_array = heap_to_sorted_array(root, &size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    free(sorted_array);
    return 0;
}
