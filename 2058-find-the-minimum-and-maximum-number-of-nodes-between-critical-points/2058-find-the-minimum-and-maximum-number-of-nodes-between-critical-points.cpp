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
    int sgn(int n) {
        return n > 0 ? 1 : n < 0 ? -1 : 0;
    }
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *curr = head->next, *prev = head;
        int prevCritical = -1, firstCritical = -1;
        int i = 0;
        int m = 1e5 + 1, M = 0;
        while(curr->next) {
            int nextV = curr->next->val;
            int prevV = prev->val;
            int currV = curr->val;
            
            if(sgn(nextV - currV)*sgn(currV - prevV) < 0LL) {
                if(firstCritical == -1) {
                    firstCritical = i;
                    prevCritical = i;
                }
                else {
                    m = min(m, i-prevCritical);
                    M = max(M, i-firstCritical);
                    prevCritical = i;
                }
            }
            
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(M == 0) return {-1, -1};
        return {m, M};
    }
};