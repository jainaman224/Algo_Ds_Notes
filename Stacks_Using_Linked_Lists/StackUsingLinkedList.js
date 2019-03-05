class node{
  constructor(value) //initializing node for usage
  {
    this.value=value;
    this.next=null;
  }
}
class stack
{
  constructor()
  {
    this.top=null; //defining top,bottom,length of the the stack
    this.bottom=null;
    this.length=0;
  }
  peek()
  {
    return this.top; //simply return top node 
  }
  push(value)
  {
    const newNode=new node(value);
    if(this.length===0) //check if the stack as one element
    {
      this.top=newNode;
      this.bottom=newNode;
    }
    else
    {
    const holdingpointer=this.top; 
    this.top=newNode;
    this.top.next=holdingpointer;
    }
    this.length++;
    return this;
  }
  pop()
  {
    if(!this.top) //if no element
    {
      return null;
    }
    if(this.top===this.bottom) 
    {
      this.bottom=null;
    }
    const holdingpointer=this.top;
    this.top=this.top.next;
    this.length--;
    return this;
  }
}
const myStack=new stack();
myStack.push(1);
myStack.push(2);
myStack.push(3);
myStack.pop();
myStack.peek();
