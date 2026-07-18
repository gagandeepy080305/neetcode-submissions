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
public://optimal solution 
//T.C. - O(n)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(cnt<k){//check if there exists k nodes
            if(temp==NULL)return head;
            cnt++;
            temp = temp->next;
        }
        //recursively call the function for the remaining nodes
        ListNode* prevNode = reverseKGroup(temp,k);
        temp = head;
        cnt = 0;
        //attach the first part of the LL at the begining of the reversed LL
        while(cnt<k){
            ListNode* next = temp->next;
            temp->next=prevNode;
            prevNode = temp;
            temp=next;
            cnt++;
        }
        return prevNode;
    }
};
