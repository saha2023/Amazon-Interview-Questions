class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy = new ListNode(-1);
        ListNode *c1 = list1, *c2 = list2, *prev = dummy;

        while(c1 != NULL and c2 != NULL) {
            if(c1->val > c2->val)
                swap(c1, c2);
            prev->next = c1;
            prev = prev->next;
            c1 = c1->next;
        }
        prev->next = c1!= NULL ? c1 : c2;
        return dummy->next;
    }
};