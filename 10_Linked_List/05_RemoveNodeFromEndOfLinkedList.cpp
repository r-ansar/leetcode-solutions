//Statement

// You are given the beginning of a linked list head, and an integer n.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* fast=dummy;
        ListNode* slow=dummy;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* todel=slow->next;
        slow->next=slow->next->next;
        delete todel;
        return dummy->next;
    }
};

//Or

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* t=head;
        while(t){
            t=t->next;
            size++;
        }
        if(size==n){
            t=head->next;
            delete head;
            head=t;
            return head;
        }
        t=head;
        for(int i=0;i<size-n-1;i++){
            t=t->next;
        }
        ListNode* addr=t->next->next;
        delete t->next;
        t->next=addr;
        return head;
    }
};