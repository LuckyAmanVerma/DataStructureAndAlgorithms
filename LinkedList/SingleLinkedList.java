class SingleLinkedList{
    Node head;
    class Node{
        String data;
        Node next;
        Node(String data){
            this.data=data;
            this.next=null;
        }
    }
    public void addFirst(String data){
        Node newNode = new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
    }
    public void addLast(String data){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        Node currentNode =head;
        while(currentNode.next!=null){
            currentNode=currentNode.next;
        }
        Node newNode = new Node(data);
        currentNode.next=newNode;
    }
    public int lengthList(){
        int i=0;
        if(head==null){
            System.out.println("List is empty");
            return 0;
        }
        Node currentNode = head;
        while(currentNode!=null){
            i++;
            currentNode=currentNode.next;
        }
        return i;
    }
    public void printList(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        Node currentNode =head;
        while(currentNode!=null){
            System.out.print(currentNode.data +" -> ");
            currentNode=currentNode.next;
        }
        System.out.println("NULL");
    }
    public void deleteNodeByData(String data){
        if(head ==null){
            System.out.println("List is empty");
        }
        Node currentNode=head,prev=null;
        while(currentNode!=null && currentNode.data!=data){
            prev=currentNode;
            currentNode=currentNode.next;
        }
        if(currentNode==null){
            System.out.println(data+" not exists in linked List");
            return;
        }
        prev.next=currentNode.next;
    }
    public static void main(String args[]){
       SingleLinkedList LL = new SingleLinkedList();
       LL.addFirst("Two");
       LL.addFirst("One");
       LL.addLast("Three");
       LL.deleteNodeByData("Two");
       LL.printList();
       System.out.println(LL.lengthList());
    }
}