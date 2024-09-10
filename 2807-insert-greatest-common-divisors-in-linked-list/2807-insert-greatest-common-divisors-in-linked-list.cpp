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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* temp1 = res;
        ListNode* temp2 = head;
        
        while(temp2 && temp2->next) {
            temp1->next = new ListNode(temp2->val);
            if(temp2->next) {
                temp1 = temp1->next;
                temp1->next = new ListNode(__gcd(temp2->val, temp2->next->val));
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        temp1->next = new ListNode(temp2->val);
        return res->next;
    }
};