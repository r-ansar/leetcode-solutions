//Statement

// You are given the head of a singly linked-list.
// The positions of a linked list of length = 7 for example, can intially be represented as:
// [0, 1, 2, 3, 4, 5, 6]
// Reorder the nodes of the linked list to be in the following order:
// [0, 6, 1, 5, 2, 4, 3]
// Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:
// [0, n-1, 1, n-2, 2, n-3, ...]
// You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return; // less than 3 nodes, nothing to do

        // 1️⃣ Find middle using slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2️⃣ Reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr; // split the list
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* second = prev; // head of reversed half

        // 3️⃣ Merge two halves
        ListNode* first = head;
        while(second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};

//Or

class Solution {
public:
    void reorderList(ListNode* head) {
        int size=0;
        ListNode* temp=head;
        ListNode* mid=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(size<3){
            return;
        }
        for(int i=0;i<size/2-1;i++){
            mid=mid->next;
        }
        ListNode* reversed=mid->next;
        mid->next=NULL;
        ListNode* curr=reversed;
        ListNode* pre=NULL;
        while(curr!=NULL){
            ListNode* temp2=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp2;
        }
        reversed=pre;
        ListNode* tomerge=head;
        while(tomerge!=NULL){
            ListNode* t1=tomerge->next;
            ListNode* t2=reversed->next;
            tomerge->next=reversed;
            if(t1==NULL){
                break;
            }
            reversed->next=t1;
            tomerge=t1;
            reversed=t2;
        }
    }
};
