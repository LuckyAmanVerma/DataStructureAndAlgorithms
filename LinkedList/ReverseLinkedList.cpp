/*
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
    newNode->next=head2 [2]=>[1]->null
    head2=newNode head2 =[2]=>[1]=>null
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head2 = nullptr;
        while (head != nullptr) {
            ListNode* newNode = new ListNode(head->val);
            if (head2 == nullptr) {
                head2 = newNode;
            } else {
                newNode->next = head2;
                head2 = newNode;
            }
            head = head->next;
        }
        return head2;
    }
};