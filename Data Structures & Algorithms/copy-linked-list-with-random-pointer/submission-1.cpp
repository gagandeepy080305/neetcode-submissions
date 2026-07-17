/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public://optimal solution with improved space complexity
//T.C. - O(n)
//S.C. - O(1)
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* temp = head;
        // Step 1: Insert copied nodes
        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        temp = head;
        
        // Step 2: Set random pointers
        while(temp!=NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* dummy = new Node(0);
        Node* copy = dummy;
        temp = head;

        // Step 3: Seperate the chain
        while(temp!=NULL){
            copy->next = temp->next;
            copy=copy->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
