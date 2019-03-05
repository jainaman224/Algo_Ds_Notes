class linkedlist
{
  constructor(value)
  {
    this.head={ //defining a linked list(access) O(1)
      value:value,
      next:null
    }
    this.length=1;
    this.tail=this.head;
  }
  append(value) //function to add a node at the end of a existing node O(1)
  {
    const newNode={
      value:value,
      next:null
    };
  this.tail.next=newNode;
  this.tail=newNode;
  this.length++;
  return this;
  }
  prepend(value) //adding a node to beginning of a linked list
  {
    const newNode={
      value:value,
      next:null
    }
    newNode.next=this.head;
    this.head=newNode;
    this.length++
    return this;
  }
  insert(index,value)
  {
    if(index>=this.length)
    {
      return this.append(value) //we can do anything in this step such as throwing error or any other althernative
    }
    const newNode={
      value:value,   //defining new node to be inserted
      next:null
    };
    const leader=this.traverseToIndex(index-1);
    const holdingpointer=leader.next;
    leader.next=newNode;
    newNode.next=holdingpointer;
    this.length++;
    return this.printlist;
  }
  traverseToIndex(index)
  {
    let counter=0;
    let currentNode=this.head; 
    while(counter!==index)
    {
      currentNode=currentNode.next;
      counter++;
    }
    return currentNode;
  }
  remove(index)
  {
    //check parameters if you want
    const leader=this.traverseToIndex(index-1);
    const unwantedNode=leader.next;
    leader.next=unwantedNode.next;
    this.length--;
    return this.printlist;
  }
  printlist() //printing entire list in form of an array
  {
    const array=[];
    let currentNode=this.head;
    while(currentNode!==null)
    {
      array.push(currentNode.value);
      currentNode=currentNode.next;
    }
    return array;
  }
}
const mylinkedlist=new linkedlist(10);
mylinkedlist.append(20);
mylinkedlist.append(30);
mylinkedlist.prepend(5);
mylinkedlist.insert(3,25);
mylinkedlist.remove(3);
//mylinkedlist.printlist();
console.log(mylinkedlist);
