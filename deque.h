#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DequeNode {
    int value;
    struct DequeNode* prevNode;
    struct DequeNode* nextNode;
} DequeNode;

typedef struct {
    DequeNode* firstNode;
    DequeNode* lastNode;
} Deque;

Deque* createDeque();
void destroyDeque(Deque* deque);

int isEmpty(Deque* deque);

int popLeft(Deque* deque);
int popRight(Deque* deque);

void pushLeft(Deque* deque, int value);
void pushRight(Deque* deque, int value);

void rotateLeft(Deque* deque);
void rotateRight(Deque* deque);

void displayDeque(Deque* deque);


#endif