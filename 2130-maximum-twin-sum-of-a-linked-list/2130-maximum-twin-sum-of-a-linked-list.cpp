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
    void pair_sm(ListNode* curr, ListNode* &fr, int &mx)
    {
        if(curr == nullptr)
            return;
        
        pair_sm(curr->next, fr, mx);
        mx = max(mx, curr->val + fr->val);
        fr = fr->next;
    }
    
    int pairSum(ListNode* head) {
    
        
        ListNode* fr = head;
        int mx = 0;
        pair_sm(head, fr, mx);
        
        return mx;
    }
    
};