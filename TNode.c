#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int value;
    struct TNode* next;
};

struct TNode* createNode(int val) {
    struct TNode* newNode = (struct TNode*)malloc(sizeof(struct TNode));
    if (newNode == NULL) {
        printf("Speicherallokierung fehlgeschlagen.");
        return NULL;
    }
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct TNode** headRef, int val) {
    struct TNode* newNode = createNode(val);
    if (newNode == NULL) {
        printf("Fehler beim Anhängen des Knotens: Speicherallokierung fehlgeschlagen.");
        return;
    }

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct TNode* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteLinkedList(struct TNode** headRef) {
    if (*headRef == NULL) {
        printf("Die Linked List ist bereits leer.\n");
        return;
    }

    struct TNode* current = *headRef;
    struct TNode* temp;

    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    *headRef = NULL;
    printf("Die Linked List wurde gelöscht und der Speicher freigegeben.\n");
}

int main() {
    struct TNode* head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    printf("Die Linked List vor dem Löschen:\n");

    deleteLinkedList(&head); 

    return 0;
}
