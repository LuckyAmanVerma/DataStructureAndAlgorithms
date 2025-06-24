/*
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);

*/
class DoublyLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!tail)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (!head && index > 0)
            return; // If list is empty and index is not 0, do nothin
        if (index < 0)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
            if (current == nullptr)
                return; // If index is out of bounds, do nothing
        }
        if (current->next == nullptr){
            addAtTail(val);
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;    
    }

    void get(int index) {
       if(!head || index < 0) {
           return; // If list is empty or index is negative, do nothing
       }
         Node *current = head;
         for (int i = 0; i < index; i++) {
            current = current->next;
            if (current == nullptr) {
                return; // If index is out of bounds, do nothing
            }
         }
            return current->data; // Return the data at the specified index
    }

    void deleteAtIndex(int index){
        if (!head || index < 0) {
            return; // If list is empty or index is negative, do nothing
        }
        Node *current = head;

        if(current->prev==nullptr && current->next==nullptr && index == 0) { 
            head=nullptr;
            tail=nullptr;
            delete current; // If the node to delete is the only node, clear the list
            return;
        }

        for (int i = 0; i < index; i++) {
            current = current->next;
            if (current == nullptr) {
                return; // If index is out of bounds, do nothing
            }
        } 
       current->prev=current->prev->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev; // Adjust the next node's previous pointer
        }

    }
};