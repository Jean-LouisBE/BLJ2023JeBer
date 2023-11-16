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

void updateAllNodeValues(struct TNode* head, int newValue) {
    if (head == NULL) {
        printf("Die Linked List ist leer.\n");
        return;
    }

    struct TNode* current = head;
    while (current != NULL) {
        current->value = newValue;
        current = current->next;
    }
}

void printLinkedList(struct TNode* head) {
    if (head == NULL) {
        printf("Die Linked List ist leer.\n");
        return;
    }

    struct TNode* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct TNode* head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    printf("Die Linked List vor der Aktualisierung:\n");
    printLinkedList(head);

    int newValueForAllNodes = 50;
    updateAllNodeValues(head, newValueForAllNodes);

    printf("\nDie Linked List nach der Aktualisierung aller Knoten:\n");
    printLinkedList(head);

    struct TNode* current = head;
    struct TNode* temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}
