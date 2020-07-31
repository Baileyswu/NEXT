/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void merge(ListNode* a, ListNode* b) {
        ListNode* s, *t;
        while(a && b) {
            s = a;
            t = b;
            a = a->next;
            b = b->next;
            s->next = t;
            t->next = a;
        }
    }
    ListNode* reverse(ListNode* h) {
        if(!h) return h;
        ListNode *p=h->next, *q=nullptr;
        h->next = nullptr;
        while(p) {
            q = p->next;
            p->next = h;
            h = p;
            p = q;
        }
        return h;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head->next;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        ListNode* h;
        if(slow) {
            h = slow->next;
            slow->next = nullptr;
        }
        // cout << h->val;
        h = reverse(h);
        merge(head, h);
    }
};