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
public://brute force(my solution)
//T.C - O(n)
//S.C - O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }   
        int frombeg = cnt-n+1;
        if(frombeg==1){
            ListNode *newHead = head->next;
            delete(head);
            return newHead;
        }
        temp = head;
        ListNode *prev = NULL;
        int i=1;
        while( i<frombeg){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
    }
};
