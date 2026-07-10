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
public://optimal 
//T.C - O(n)
//S.C - O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);   // dummy node before head
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Step 1: Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 2: Move both until fast reaches end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Delete target node
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;

        return dummy.next;
    }
};

