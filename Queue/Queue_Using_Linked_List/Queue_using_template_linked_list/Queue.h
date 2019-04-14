//  queue.h
//
//  Created by Nandu Kalidindi on 21/09/16.
//  Copyright © 2016 Nanda Kishore Kalidindi. All rights reserved.
//

#ifndef queue_h
#define queue_h

/*
 * Class: Queue
 * Usage: Queue<int>
 *        Queue<double>
 *        (Queue<string> is not working as expected)
 * ----------
 * This header defines a generic template for Queue datastructure.
 * genericType is to be provided by the client.
 *
 * Behind the abstraction:
 * Implementation using linked lists where enqueuing and dequeuing
 * both perform without the need for pointer traversals.
 *
 * Enqueue operation is dealt by the tail pointer as adding an element
 * to the end only requires the last pointer
 *
 * Dequeue operation is dealt by the head pointer as removing an element
 * would require the previous pointer to attach the nodes properly. Head
 * node which always points the the first node serves the purpose of a
 * previous pointer
 *
 * TODO: Strings are to be handled well, for some reason a BAD_ACCESS memory error is thrown
 */

template <typename genericType>
class Queue {
public:
    /*
     * Constructor: Queue
     * Usage: Queue<int> queue;
     *        Queue<double> queue;
     * -----------------------------------------
     * Constructor initializes the nodeCount to 0, head and tail
     * pointers to NULL. NO ARGUMENTS are required.
     */
    Queue();

    /*
     * Destructor: Queue
     * Usage: delete queue;
     * -----------------------------------------
     * Cleans up the memory allocated for each node in the queue
     */
    ~Queue();

    /*
     * Method: size
     * Usage: queue.size();
     * ReturnType: Integer
     * -----------------------------------------
     * Returns the number of elements in the Queue
     * Helpful while checking the presence of elements in the queue
     */
    int size();

    /*
     * Method: printQueueFirstToLast
     * Usage: queue.printQueueFirstToLast();
     * ReturnType Void
     * -----------------------------------------
     * Prints the elements of the queue in the order of their insertion
     */
    void printQueueFirstToLast();

    /*
     * Method: enqueue
     * Usage: queue.enqueue(element);
     * ReturnType: Void
     * -----------------------------------------
     * Adds an element to the end of the queue, increments the queue size
     * and updates tail pointer accordingly
     */
    void enqueue(genericType element);

    /*
     * Method: dequeue
     * Usage: queue.dequeue();
     * ReturnType: genericType (int, double, unsigned long etc.)
     * -----------------------------------------
     * Removes an element from the top of the queue, decrements the queue size
     * and updates the head pointer accordingly
     */
    genericType dequeue();

private:

    /*
     * Structure: node
     * -----------------------------------------
     * Building block of the queue data structure
     */
    struct node {
        genericType element;
        node *next;
    };

    /*
     * Integer: nodeCount
     * -----------------------------------------
     * Keeps track of the queue size at any point in time
     */
    int nodeCount;

    /*
     * Pointer: head, tail
     * -----------------------------------------
     * Head points to the START of the list, helps enqueuing elements
     * Tail points to the END of the list, helps dequeuing elements
     */
    node *head, *tail;
};

#include "queue.cpp"

#endif /* queue_h */
