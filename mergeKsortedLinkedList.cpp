class Solution {
private:
    ListNode *mergeLinkedLists(ListNode *headOne, ListNode *headTwo) {
  // Write your code here.
        ListNode* one = headOne;
        ListNode* two = headTwo;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        
        while(one != NULL and two != NULL){
            if(one->val >= two->val)
                swap(one , two);
            pre->next = one;
            pre = pre->next;
            one = one->next;
        }
        
        if(one != NULL){
            pre->next = one;
        }
        
        if(two != NULL){
            pre->next = two;
        }
        
        return dummy->next;
    }
    ListNode *merge(vector<ListNode*>& lists, int si, int ei){
        if(si>ei) return NULL;
        if(si==ei) return lists[si];
        int mid = (si+ei)/2;
        ListNode *l1 = merge(lists,si,mid);
        ListNode *l2 = merge(lists,mid+1,ei);

        return mergeLinkedLists(l1,l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return merge(lists,0, lists.size()-1);
    }
};