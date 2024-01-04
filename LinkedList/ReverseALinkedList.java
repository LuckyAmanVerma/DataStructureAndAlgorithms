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