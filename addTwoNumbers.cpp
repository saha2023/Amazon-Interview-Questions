class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 ==nullptr) return (l1 != nullptr ? l1 : l2);
        ListNode *dummy = new ListNode(-1);
        ListNode *itr = dummy;
        int carr = 0;
        while(l1 != nullptr or l2 != nullptr or carr != 0){
            int sum = (carr+(l1 != NULL ? l1->val : 0)+(l2 != NULL ? l2->val : 0));
            int ld = sum%10;
            carr = sum/10;
            itr->next = new ListNode(ld);
            itr = itr->next;
            if (l1 != NULL) l1=l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return dummy->next;
    }
};