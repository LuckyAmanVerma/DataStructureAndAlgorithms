/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
  class MergeLinkedList{
    public ListNode mergeList(ListNode list1 , listNode list2){
        if(list1!=null && list2!==null){
            if(list1.val<list2.val){
                list1.next = mergeList(list1.next,list2);
                return list1;
            }
            if(list2.val<list1.val){
                list2.next = mergeList(list1,list2.next);
                return list2;
            }
        }
        if(list1==null){
            return list2;
        }
        return list2;
    }
  }