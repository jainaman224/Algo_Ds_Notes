//  queue.cpp
//
//  Created by Nandu Kalidindi on 21/09/16.
//  Copyright © 2016 Nanda Kishore Kalidindi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Queue.h"

using namespace std;

/*
 * Constructor: Queue
 * Usage: Queue<int> queue;
 *        Queue<double> queue;
 * -----------------------------------------
 * Constructor initializes the nodeCount to 0, head and tail
 * pointers to NULL. NO ARGUMENTS are required.
 */
template <typename genericType>
Queue<genericType>::Queue() {
    nodeCount = 0;
    head = tail = NULL;
}

/*
 * Destructor: Queue
 * Usage: delete queue;
 * -----------------------------------------
 * Dequeuing until no elements are present
 */
template <typename genericType>
Queue<genericType>::~Queue() {
    genericType element;
    while(head != NULL) {
        element = dequeue();
    }
}

/*
 * Method: size
 * Usage: queue.size();
 * ReturnType: Integer
 * -----------------------------------------
 * Return the nodeCount private variable
 */
template <typename genericType>
int Queue<genericType>::size() {
    return nodeCount;
}


/*
 * Method: printQueueFirstToLast
 * Usage: queue.printQueueFirstToLast();
 * ReturnType Void
 * -----------------------------------------
 * Assign a new pointer to the start of the queue and iterate
 * through by printing the element at hand
 */
template <typename genericType>
void Queue<genericType>::printQueueFirstToLast() {
    node *iterator = head;
    while(iterator != NULL) {
        cout << iterator->element << endl;
        iterator = iterator->next;
    }
}

/*
 * Method: enqueue
 * Usage: queue.enqueue(element);
 * ReturnType: Void
 * -----------------------------------------
 * Differentiate between and empty queue and a non-empty one for
 * proper linkages. Tail pointer is advanced with each enqueue op
 *
 * Increment the nodeCount accordingly
 */
template <typename genericType>
void Queue<genericType>::enqueue(genericType element) {
    node *enqueueNode = new node;
    enqueueNode->element = element;
    enqueueNode->next = NULL;
    if(size() == 0) {
        head = tail = enqueueNode;
    } else {
        tail->next = enqueueNode;
        tail = enqueueNode;
    }
    nodeCount++;
}

/*
 * Method: dequeue
 * Usage: queue.dequeue();
 * ReturnType: genericType (int, double, unsigned long etc.)
 * -----------------------------------------
 * Only perform dequeue operation when the queue is non-empty, else
 * memory problems will bubble up due to the possible deletion of
 * a memory location which is not allocated to the program
 *
 * Decrement the nodeCount accordingly
 */
template <typename genericType>
genericType Queue<genericType>::dequeue() {
    genericType element = NULL;
    if(size() != 0) {
        node *dequeueNode = head;
        head = head->next;
        nodeCount--;
        element = dequeueNode->element;
        delete dequeueNode;
    }
    return element;
}
