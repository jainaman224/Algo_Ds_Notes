//Code for Readers-Writers problem using semaphores and threads
#include<bits/stdc++.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

sem_t m,w;				//m is mutex and w is write_block semaphore
int d = 0, readers = 0;	//d is a variable that stores what has to be read pr written and readers is for number of readers

void *reader(void *arg){
	long i = ((long)arg);//Tells us which reader is supposed to read
	sem_wait(&m);		//waits for mutex to be released
	readers + = 1;		//increment number of readers
	if(readers == 1)
		sem_wait(&w);	//If there is one reader then wait for write block to be released
	sem_post(&m);		//Mutex is released
	cout<<"Reader "<<i<<" reads "<<d<<endl;
	sleep(1);
	cout<<"Done";
	sem_wait(&m);		//waits for mutex to be released
	readers - = 1;		//Decrement number of readers
	if(readers == 0)	//If no reader is there
		sem_post(&w);	//Release the write block
	sem_post(&m);		//Release mutex
		
}

void *writer(void *arg){
	long i = ((long)arg);//Tells us which writer is supposed to write
	sem_wait(&w);		//Waits for write block to be released
	d++;
	cout<<"Writer "<<i<<" writes "<<d<<endl;
	sleep(1);
	cout<<"Done";
	sem_post(&w);		//Release the write block
}

int main(){
	long i,b;
	pthread_t rthreads[5],wthreads[5];
  	sem_init(&m,0,1);	//Initializes mutex
  	sem_init(&w,0,1);	//Initializes write block semaphore
  	//Loop for creating threads
 	for(i=0;i<=2;i++){
    		pthread_create(&rthreads[i],NULL,reader,(void *)i);
    		pthread_create(&wthreads[i],NULL,writer,(void *)i);
  	}
  	//Loop for joining threads
  	for(i=0;i<=2;i++){
    		pthread_join(wthreads[i],NULL);
    		pthread_join(rthreads[i],NULL);
  	}
  return 0;
}
