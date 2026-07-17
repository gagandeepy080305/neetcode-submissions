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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val+temp2->val+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = newNode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int sum = temp1->val+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr=newNode;
            temp1= temp1->next;
        }
        while(temp2!=NULL){
            int sum = temp2->val+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr=newNode;
            temp2= temp2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return dummyNode->next;
    }
};
