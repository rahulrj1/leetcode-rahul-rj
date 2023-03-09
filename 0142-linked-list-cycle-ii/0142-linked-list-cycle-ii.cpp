/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode *fast = head->next->next, *slow = head->next;
        while(fast != slow) {
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = head; 
        while(fast != slow) {
            fast = fast->next; slow = slow->next; 
        }
        return fast;
    }
};