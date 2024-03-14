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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        mp[0] = new ListNode(0); mp[0]->next = head;
        
        ListNode *curr = mp[0]; 
        int sum = 0;
        while(curr->next != NULL) {
            curr = curr->next;
            sum += curr->val;
            
            if(mp.find(sum) == mp.end()) {
                mp[sum] = curr;
            }
            else {
                ListNode* temp = mp[sum]->next, *prev = mp[sum];
                int tempSum = sum;
                while(temp != curr) {
                    tempSum += temp->val;
                    mp.erase(tempSum);
                    temp = temp->next;
                }
                prev->next = curr->next;
            }
        }
        return mp[0]->next;
    }
};