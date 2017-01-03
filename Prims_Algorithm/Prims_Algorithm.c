#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node* ptrarr[1000005];
long long int vis[1000005];

struct node{
        long long int value;
        long long int weight;
        struct node* next;
};

void adjinsert(struct node** head,long long int val,long long int weight){
        struct node* first = (struct node*)malloc(sizeof(struct node));
        first->value = val;
        first->weight = weight;
        first->next = *head;
        *head = first;
}

struct node arr[1000005];
long long int heapsize;

void heapify(long long int i){
        long long int left = arr[2*i].weight;
        long long int right = arr[2*i+1].weight;
        long long int root = arr[i].weight;
        long long int lv = arr[2*i].value;
        long long int rv = arr[2*i+1].value;
        long long int mv = arr[i].value;

        if(i>=1 && i<=heapsize && (2*i+1<=heapsize || 2*i<=heapsize )){
                if( left <= right && left <= root){
                        arr[i].weight = left;
                        arr[i].value = lv;
                        arr[2*i].weight = root;
                        arr[2*i].value = mv;
                        heapify(2*i);
                }
                else if( right < left && right < root){
                        arr[i].weight = right;
                        arr[i].value = rv;
                        arr[2*i+1].weight = root;
                        arr[2*i+1].value = mv;
                        heapify(2*i+1);
                }
        }
}

void formHeap(){
        long int i;
        for(i=heapsize/2;i>=1;i--){
                heapify(i);
        }
}

void insert(long long int vertex, long long int val){
        heapsize++;
        arr[heapsize].weight = val;
        arr[heapsize].value = vertex;
        long long int parent = heapsize/2;
        long long int child = heapsize;
        while(arr[parent].weight > val && parent >= 1){
                arr[child].weight = arr[parent].weight;
                arr[parent].weight = val;
                arr[child].value = arr[parent].value;
                arr[parent].value = vertex;
                child = parent;
                parent = parent/2;
        }
        return;
}

struct node pop(){
        struct node poped;
        poped.weight = arr[1].weight;
        poped.value = arr[1].value;
        arr[1].weight = arr[heapsize].weight;
        arr[1].weight = arr[heapsize].weight;
        arr[1].value = arr[heapsize].value;
        arr[1].value = arr[heapsize].value;
        heapsize--;
        heapify(1);
        return poped;
}

void print(){
        long long int i;
        printf("-------------------HEAP-----------------\n");
        for(i=1;i<=heapsize;i++){
                printf("v: %lld w: %lld ",arr[i].value, arr[i].weight);
                printf("\n");
        }
        printf("----------------------------------------\n");
}

long long int res,counter,spanedge;
struct node poped;

long long int prims(long long int v){
        if(spanedge == counter)
                return res;

        struct node * current;
        current = ptrarr[v];
        while(current!=NULL){
                if(vis[current->value]==0){
                        insert(current->value,current->weight);
                }
                current = current->next;
        }

        poped = pop();
        while(vis[poped.value]==1){
                poped = pop();
        }
        res = res + poped.weight;
        counter++;
        vis[poped.value] = 1;
        return prims(poped.value);
}

int main(){
    long long int total,t,x,i,v,e,v1,v2,w;

	t = 1;
	srand(time(NULL));

        for(x=0;x<t;x++){
                for(i=0;i<1000005;i++){
                        ptrarr[i] = NULL;
                        vis[i] = 0;
                }

                v = 5;
		e = 10;

                heapsize = 0;
                total = 0;
                spanedge = v-1;
                res = 0;
                counter = 0;

                for(i=0;i<e;i++){
			v1 = (long long int) (rand() % v + 1);
			v2 = (long long int) (rand() % v + 1);
			w = (long long int) rand()%1000;
                        if(v1!=v2){
                                adjinsert(&ptrarr[v1],v2,w);
                                adjinsert(&ptrarr[v2],v1,w);
                        }
                        total += w;
                }

                vis[1] = 1;
                printf("Weight of minimum spanning tree : %lld\n", prims(1));
        }


        return 0;
}
