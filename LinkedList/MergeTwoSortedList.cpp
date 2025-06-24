/*
list1 =[1]=> [2] => [4] => null
list2 =[1]=> [3] => [4] => null
// Output: [1]=> [1]=> [2]=> [3]=> [4]=> [4]=> null

head 2 =null
First iteration:
head 2  =[1]->[1]=>null
Second iteration:
new node = [2]->[3]=>null
head 2 = [1]->[1]->[2]->[3]->null
Third iteration:
new node = [4]->[4]=>null
head 2 = [1]->[1]->[2]->[3]->[4]->[4]=>null


Output: [1]=> [1]=> [2]=> [3]=> [4]=> [4]=> null
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head2 = nullptr;
        ListNode* tail = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* newNode = nullptr;
            if (list1->val <= list2->val) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }
            if (head2 == nullptr) {
                head2 = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        // Attach remaining nodes from list1
        while (list1 != nullptr) {
            ListNode* newNode = new ListNode(list1->val);
            if (head2 == nullptr) {
                head2 = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
        }
        // Attach remaining nodes from list2
        while (list2 != nullptr) {
            ListNode* newNode = new ListNode(list2->val);
            if (head2 == nullptr) {
                head2 = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            list2 = list2->next;
        }
        return head2;
    }
};