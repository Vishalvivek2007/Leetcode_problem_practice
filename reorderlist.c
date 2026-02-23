/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL)
        return;

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second = slow->next;
    slow->next = NULL;   // break the list into two halves

    // Step 2: Reverse second half
    struct ListNode* prev = NULL;
    struct ListNode* curr = second;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // prev is now head of reversed second half
    struct ListNode* front =head;
    struct ListNode* temp1= front->next;
    struct ListNode* temp2= prev->next;
    while(front!=NULL && prev!=NULL && front!=prev && front->next!=prev){
        front->next= prev;
        prev->next=temp1;
        front=temp1;
        prev=temp2;
        if(temp1!=NULL){
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            temp2=temp2->next;
        }
    }
    return;
}