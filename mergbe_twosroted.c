struct ListNode* mergeTwoLists(struct ListNode* head1, struct ListNode* head2) {

    struct ListNode dummy;     
    struct ListNode* temp = &dummy;

    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {

        if (head1->val < head2->val) {
            temp->next = head1;
            head1 = head1->next;
        } 
        else {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;

    if (head2 != NULL)
        temp->next = head2;

    return dummy.next;
}