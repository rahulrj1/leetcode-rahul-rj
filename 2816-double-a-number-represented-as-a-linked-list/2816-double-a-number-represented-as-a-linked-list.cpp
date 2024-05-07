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
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *ne;
        while(curr) {
            ne = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ne;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseLL(head);
        int carry = 0;
        ListNode *curr = head, *prev;
        while(curr) {
            curr->val *= 2; curr->val += carry;
            carry = curr->val > 9 ? 1 : 0;
            curr->val %= 10;
            prev = curr;
            curr = curr->next;
        }
        if(carry) prev->next = new ListNode(1);
        return reverseLL(head);
    }
};