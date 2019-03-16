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
    return this.first; //simple see the first node
  }
  enqueue(value)
  {
    const newNode=new node(value);
    if(this.length===0)
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
  dequeue()
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

myqueue.peek();
myqueue.dequeue();
myqueue.dequeue();
myqueue.dequeue();
