#include <stdio.h>
#include <stdlib.h>
#include "deque.h"


Deque* createDeque() {
    Deque* deque = malloc(sizeof(Deque));
    if (!deque) return NULL;
    deque->firstNode = NULL;
    deque->lastNode = NULL;
    return deque;
}

void destroyDeque(Deque* deque) {
    while (!isEmpty(deque)) popLeft(deque);
    free(deque);
}

int isEmpty(Deque* deque) {
    return deque->firstNode == NULL;
}

int popLeft(Deque* deque) {
    if (isEmpty(deque)) return -1;

    DequeNode* nodeToPop = deque->firstNode;
    int value = nodeToPop->value;

    if (deque->firstNode == deque->lastNode) {
        deque->firstNode = deque->lastNode = NULL;
    } else {
        deque->firstNode = nodeToPop->nextNode;
        deque->firstNode->prevNode = deque->lastNode;
        deque->lastNode->nextNode = deque->firstNode;
    }

    free(nodeToPop);
    return value;
}

int popRight(Deque* deque) {
    if (isEmpty(deque)) return -1;

    DequeNode* nodeToPop = deque->lastNode;
    int value = nodeToPop->value;

    if (deque->firstNode == deque->lastNode) {
        deque->firstNode = deque->lastNode = NULL;
    } else {
        deque->lastNode = nodeToPop->prevNode;
        deque->lastNode->nextNode = deque->firstNode;
        deque->firstNode->prevNode = deque->lastNode;
    }

    free(nodeToPop);
    return value;
}

void pushLeft(Deque* deque, int value) {
    DequeNode* nodeToPush = malloc(sizeof(DequeNode));
    if (!nodeToPush) return;
    
    nodeToPush->value = value;

    if (isEmpty(deque)) {
        // Empty deque
        deque->firstNode = deque->lastNode = nodeToPush;
        nodeToPush->nextNode = nodeToPush->prevNode = nodeToPush;
    } else {
        nodeToPush->nextNode = deque->firstNode;
        nodeToPush->prevNode = deque->lastNode;

        deque->lastNode->nextNode = nodeToPush;
        deque->firstNode->prevNode = nodeToPush;
        deque->firstNode = nodeToPush;
    }
}

void pushRight(Deque* deque, int value) {
    DequeNode* nodeToPush = malloc(sizeof(DequeNode));
    if (!nodeToPush) return;
    
    nodeToPush->value = value;

    if (isEmpty(deque)) {
        deque->firstNode = deque->lastNode = nodeToPush;
        nodeToPush->nextNode = nodeToPush->prevNode = nodeToPush;
    } else {
        nodeToPush->nextNode = deque->firstNode;
        nodeToPush->prevNode = deque->lastNode;
        
        deque->lastNode->nextNode = nodeToPush;
        deque->firstNode->prevNode = nodeToPush;
        deque->lastNode = nodeToPush;
    }
}

void rotateLeft(Deque* deque) {
    deque->firstNode = deque->firstNode->nextNode;
    deque->lastNode = deque->firstNode->prevNode;
}

void rotateRight(Deque* deque) {
    deque->lastNode = deque->lastNode->prevNode;
    deque->firstNode = deque->lastNode->nextNode;
}

void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    DequeNode* firstNode = deque->firstNode;
    DequeNode* currentNode = firstNode;
    printf("Deque: ");
    do {
        printf("%d ", currentNode->value);
        currentNode = currentNode->nextNode;
    } while (currentNode != firstNode);
    printf("\n");
}