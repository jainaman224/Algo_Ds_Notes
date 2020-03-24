// Code for Readers-Writers problem using semaphores and threads
#include<bits/stdc++.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

// m is mutex and w is write_block semaphore
sem_t m, w;
// d is a variable that stores what has to be read or written and readers is for number of readers
int d = 0, readers = 0;

void *reader(void *arg)
{
    // Tells us which reader is supposed to read
    long i = ((long)arg);
    // Waits for mutex to be released
    sem_wait(&m);
    // Increment number of readers
    readers += 1;
    if(readers == 1)
        // If there is one reader then wait for write block to be released
        sem_wait(&w);
    // Mutex is released
    sem_post(&m);
    cout << "Reader " << i << " reads " << d << endl;
    sleep(1);
    // Waits for mutex to be released
    sem_wait(&m);
    // Decrement number of readers
    readers -= 1;
    // If no reader is there
    if(readers == 0)
        // Release the write block
        sem_post(&w);
    // Release mutex	
    sem_post(&m);
}

void *writer(void *arg)
{
    // Tells us which writer is supposed to write
    long i = ((long)arg);
    // Waits for write block to be released
    sem_wait(&w);
    d++;
    cout << "Writer " << i << " writes " << d << endl;
    sleep(1);
    // Release the write block
    sem_post(&w);
}

int main()
{
    long i, b;
    pthread_t rthreads[5], wthreads[5];
    // Initializes mutex
    sem_init(&m, 0, 1);
    // Initializes write block semaphore
    sem_init(&w, 0, 1);	
  	
    // Loop for creating threads
    for(i = 0; i <= 2; i++)
    {
        pthread_create(&wthreads[i], NULL, writer, (void *)i);
        pthread_create(&rthreads[i], NULL, reader, (void *)i);
    }
    // Loop for joining threads
    for(i = 0; i <= 2; i++)
    {
        pthread_join(wthreads[i], NULL);
        pthread_join(rthreads[i], NULL);
    }
    return 0;
}

/* Sample Output:

Writer 0 writes 1
Reader 0 reads 1
Reader 1 reads 1
Reader 2 reads 1
Writer 1 writes 2
Writer 2 writes 3
*/
