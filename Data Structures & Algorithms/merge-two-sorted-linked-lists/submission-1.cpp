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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *start = NULL;
        ListNode *last = NULL;

        // Merge while both lists have nodes
        while (temp1 != NULL && temp2 != NULL) {
            ListNode* node;
            if (temp1->val < temp2->val) {
                node = temp1;
                temp1 = temp1->next;
            } else {
                node = temp2;
                temp2 = temp2->next;
            }

            if (start == NULL) {
                start = node;
                last = node;
            } else {
                last->next = node;
                last = node;
            }
        }

        // Attach remaining nodes
        if (temp1 != NULL) {
            if (last == NULL) {
                start = temp1;
            } else {
                last->next = temp1;
            }
        }
        if (temp2 != NULL) {
            if (last == NULL) {
                start = temp2;
            } else {
                last->next = temp2;
            }
        }

        return start;
    }
};
