class node {
  constructor(value)
  {
    this.value=value; //initializing node
    this.next=null;
  }
}
class queue{
  constructor()
  {
    this.first=null;   //defining first,last,length of the quueue
    this.last=null;
    this.length=0;
  }
  peek()
  {
    return this.first; //to simply see the first node
  }
  enqueue(value)
  {
    const newNode=new node(value);
    if(this.length===0)           //to add a node
    {
      this.first=newNode;
      this.last=newNode;
    }
    else{
      this.last.next=newNode;
      this.last=newNode;
    }
    this.length++;
    return this;
  }
  dequeue()               //to dequeue 
  {
    if(!this.first)
    {
      return null;
    }
    if(this.first===this.last)
    {
      this.last=null;
    }
    const holdingpointer=this.first;
    this.first=this.first.next;
    this.length--;
    return holdingpointer;
  }
}
const myqueue=new queue();
myqueue.enqueue(1);
myqueue.enqueue(2);
myqueue.enqueue(3);
myqueue.enqueue(4);
myqueue.peek();
myqueue.dequeue();
myqueue.dequeue();
myqueue.dequeue();

//Output:-   node { value: 3, next: node { value: 4, next: null } }
//           node with values 3 , 4 will be outputed as seen above 
