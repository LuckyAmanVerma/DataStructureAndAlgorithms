/**
    * LeetCode Problem: https://leetcode.com/problems/reverse-linked-list/
    head points to Linked List node  [1]->next->[2]->next->[3]->next->null
    head2=null;
    First iteration:
     newNode=new Node(1); [1]=>null
     head2 is null
    head2=newNode
    head2 = [1]->next->null
    head=head.next;

    Second iteration: head2= [1]=>null
    newNode =new Node(2); [2]->null
    head2 is not null;
    newNode.next=head2 [2]=>[1]->null
    head2=newNode head2 =[2]=>[1]=>null

    
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode temp2=null;
        ListNode temp=null;
        while(head!=null){
            temp2 =head.next;
            head.next=temp;
            temp=head;
            head=temp2;
        }
        head=temp;
        return head;
    }
}