class doublylinkedlist{
  constructor(value)
  {
    this.head = {
      value:value,
      next:null,
      prev:null // a new pointer is to be defined which points to previous node
    }
    this.tail=this.head;
    this.length=1;
  }
  append(value)         //for appending operation(this adds node to the end of the linked list)
  {
    const newNode={
      value:value,
      next:null,
      prev:null
    }
    newNode.prev=this.tail; 
    this.tail.next=newNode;
    this.tail=newNode;
    this.length++;
    return this;
  }
  prepend(value)      //for prepending 
  {
    const newNode={
      value:value,
      next:null,
      prev:null
    }
    newNode.next=this.head;
    this.head.prev=newNode;
    this.head=newNode;
    this.length++;
    return this;
  }
  printList()         //to print linked list in form of list(array)
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
  insert(index,value)       //inserting an element to a specific position
  {
    if(index>=this.length){
      return this.append(value); //check parameter and do the operation according to your wish
    }
    const newNode={
      value:value,
      next:null,
      prev:null //new pointer
    }
    const leader=this.traverseToIndex(index-1);
    const follower=leader.next; //node after leader 
    leader.next=newNode;
    newNode.prev=leader;    //newnode pointing to leader(previous node)
    newNode.next=follower;
    follower.prev=newNode; //follower pointing to newnode(previous)
    this.length++;
    return this.printList();
  }
  remove(index)            //O(n) time as it involves traversing
  {
    //check parameters if you want
    const leader=this.traverseToIndex(index-1);
    const unwantedNode=leader.next;
    leader.next=unwantedNode.next;
    const nodeAfterDeletedNode=unwantedNode.next;
    nodeAfterDeletedNode.prev=leader;
    this.length--;
    return this.printList();
  }
  traverseToIndex(index)        //for traversing 
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
}
const mydoublylinkedlist=new doublylinkedlist(10);
mydoublylinkedlist.append(20);
mydoublylinkedlist.append(30);
mydoublylinkedlist.prepend(5);
mydoublylinkedlist.insert(2,15);
mydoublylinkedlist.remove(2);
mydoublylinkedlist.printList();


//Output:- => [ 5, 10, 20, 30 ]
