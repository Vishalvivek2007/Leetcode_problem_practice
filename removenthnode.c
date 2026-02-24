/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len= 0;
    struct ListNode* curr  =head;
    while(curr!=NULL){
        curr=curr->next;
        len++;
    }
    int index =len-n;
    curr = head;
    struct ListNode* prev=NULL;
    struct ListNode *front = NULL;
    while(index--){
        prev=curr;
        curr=curr->next;
    }
    front=curr->next;
    if(prev!=NULL){
        prev->next=front;
    }
    if(curr==head){
        head=head->next;
    }
    free(curr);
    return head;
}