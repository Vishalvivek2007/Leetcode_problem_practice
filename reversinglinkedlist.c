/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL ||head->next==NULL){
        return head;
    }
    else if(head->next->next==NULL){
            struct ListNode* temp = head->next;
            temp->next=head;
            head->next=NULL;
            head=temp;
            return head;
    }
    else {
        struct ListNode* back=head;
        struct ListNode* curr=head->next;
        struct ListNode* front =head->next->next;
        back->next=NULL;
        while(front!=NULL){
            curr->next= back;
            back=curr;
            curr=front;
            front=front->next;
        }
        curr->next=back;

        return curr;
    }
}