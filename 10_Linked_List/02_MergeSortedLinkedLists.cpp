// Statement

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted linked list and return the head of the new sorted linked list.
// The new list should be made up of nodes from list1 and list2.


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();  
        ListNode* tail = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;  
        }

        if (list1 != NULL) tail->next = list1;
        else tail->next = list2;

        return dummy->next;  
    }
};