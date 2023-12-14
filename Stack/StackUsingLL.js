class Node {
    constructor(data) {
      this.data = data;
      this.next = null;
    }
  }
  
  class Stack {
    constructor() {
      this.head = null;
    }
  
    isEmpty() {
      return this.head === null;
    }
  
    push(data) {
      const newNode = new Node(data);
      if (this.isEmpty()) {
        this.head = newNode;
        return;
      }
      newNode.next = this.head;
      this.head = newNode;
      console.log(this.head);
    }
  
    peek() {
      if (this.isEmpty()) {
        console.log("Nothing to show");
        return;
      }
      console.log(this.head.data);
    }
  
    pop() {
      if (this.isEmpty()) {
        console.log("Stack is empty");
        return;
      }
      const data = this.head.data;
      this.head = this.head.next;
      console.log(`${data} is deleted`);
    }
    firstElement(){
        let newNode =this.head;
        while(newNode.next!==null){
            newNode =newNode.next;
        }
        console.log('firstElement is ',newNode.data);
    }
    pushAtTheBottom(data){
        let initialNode =this.head;
        while(initialNode.next!==null){
            initialNode =initialNode.next;
        }
        const newNode =new Node(data);
        initialNode.next=newNode;
    }
  }
  
  const s = new Stack();
  s.push(4);
  s.push(6);
  s.push(3);
  s.firstElement();
  s.pushAtTheBottom(1);
  s.firstElement();
  // s.pop();
  // s.peek();
  