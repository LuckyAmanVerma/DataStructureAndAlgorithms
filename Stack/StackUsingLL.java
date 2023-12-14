class StackUsingLL{
    static Node head;
    static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data=data;
            this.next=null;
        }
    }
     static class Stack{
        public static boolean isEmpty(){
        return head==null;
    }
    public static void push(int data){
        Node newNode = new Node(data);
        if(isEmpty()){
            head=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
        System.out.println(head.data);
    }
    public static void peek(){
        if(isEmpty()){
            System.out.println("Nothing to show");
            return;
        }
        System.out.println(head.data);
    }
    public static void pop(){
        int data=head.data;
        head=head.next;
        System.out.println(data+ " is deleted");
    }
    public void pushAtTheBottom(int data) {
            Node initialNode = head;
            while (initialNode.next != null) {
                initialNode = initialNode.next;
            }
            Node newNode = new Node(data);
            initialNode.next = newNode;
        }
    }
    
    public static void main(String args[]){
        Stack s= new Stack();
        s.push(4);
         s.push(6);
          s.push(3);
        //   s.pop();
        // s.peek();
    }
}