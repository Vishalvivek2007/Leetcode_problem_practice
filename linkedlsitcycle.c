/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next==NULL){
        return false;
    }   
    else{
        struct ListNode* slow = head;
        struct ListNode* fast =head->next;
        while(slow!=NULL && fast!=NULL&& slow->next!=NULL && fast->next!=NULL&& fast->next->next!=NULL){
            if(slow==fast){
                return true;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
}