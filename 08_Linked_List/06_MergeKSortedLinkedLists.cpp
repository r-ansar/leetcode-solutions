// Statement

// You are given an array of k linked lists lists, where each list is sorted in ascending order.
// Return the sorted linked list that is the result of merging all of the individual linked lists.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(INT_MIN,nullptr);
        ListNode* result=dummy;
        for(ListNode* a:lists){
            ListNode* curr=a;
            while(curr!=NULL){
                ListNode* res=result;
                while(res->next&&res->next->val<curr->val){
                    res=res->next;
                }
                ListNode* temp=res->next;
                ListNode* temp2=curr->next;
                res->next=curr;
                curr->next=temp;
                curr=temp2;
            }
        }
        return result->next;
    }
};

// Or

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        // Step 1: push first node of each list
        for (ListNode* head : lists) {
            if (head != NULL) {
                pq.push(head);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        // Step 2: process heap
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            // add to result
            tail->next = node;
            tail = tail->next;
            // Step 3: push next node of same list
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};