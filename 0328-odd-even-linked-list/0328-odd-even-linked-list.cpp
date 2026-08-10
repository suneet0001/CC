class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *eh = even;

        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;
            
            even->next=odd->next;
            even=even->next;
        }
        odd->next=eh;
        return head;
    }
};