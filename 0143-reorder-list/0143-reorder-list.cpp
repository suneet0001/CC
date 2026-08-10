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
    ListNode* rev(ListNode* head){
        ListNode *prev=NULL, *curr=head, *next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *s=head;
        ListNode *f=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* h2 = s->next;
        s->next = NULL;
        h2 = rev(h2);
        while(h2) {
            ListNode* t1 = head->next;
            ListNode* t2 = h2->next;
            head->next = h2;
            h2->next = t1;
            head = t1;
            h2 = t2;
        }
    }
};