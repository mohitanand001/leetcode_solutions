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
    ListNode* mergeNodes(ListNode* head) {

        ListNode *p1 = head, *p2 = head;
        
        while(p2)
        {
            int sm = 0;
            p2 = p2->next;
            
            while(p2 and (p2->val != 0))
            {
                sm += p2->val;
                p2 = p2->next;
            }
            
            if(p2->next == nullptr)
            {
                p1->val = sm;
                p1->next = nullptr;
                break;
            }
            
            p1->val = sm;
            p1->next = p2;
            p1 = p2;
        }
        
        return head;
    }
};