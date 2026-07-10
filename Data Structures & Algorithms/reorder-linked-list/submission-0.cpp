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
//T.C. - O(n)
//S.C. - O(1)
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *curr;
        while(fast!=NULL && fast->next != NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        curr = slow->next;
        slow->next=NULL;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode *p1 = head;
        ListNode *p2 = prev;
        while(p2!=NULL){
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;
            p1->next = p2;
            p2->next=temp1;
            p1=temp1;
            p2=temp2;
        }
    }
};
