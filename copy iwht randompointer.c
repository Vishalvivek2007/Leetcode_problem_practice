/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node* copyRandomList(struct Node* head) {
    if(head==NULL){
        return head;
    }
    struct Node* curr= head;
    int len=0;
    while(curr!=NULL){
        curr=curr->next;
        len++;
    }
    int LEN=len;
    int* hash= (int*)malloc(sizeof(int)*(len+1));
    curr=head;
    len=0;
    while(curr!=NULL){
        struct Node* temp = curr->random;
        int index=0;
        while(temp!=NULL){
            index++;
            temp=temp->next;
        }
        hash[len]=LEN-index;
        len++;
        curr=curr->next;
    }
    curr=head;
    struct Node** arr=(struct Node**)malloc(sizeof(struct Node*)*(len+1));
    for(int i=0;i<len;i++){
        arr[i]=(struct Node*)malloc(sizeof(struct Node));
        arr[i]->val=curr->val;
        curr=curr->next;
    }
    for(int i=0;i<len;i++){
        if(i<len-1){
            arr[i]->next=arr[i+1];
        }
        else{
            arr[i]->next=NULL;
        }
        if(hash[i]==len){
            arr[i]->random=NULL;
        }
        else{
            arr[i]->random=arr[hash[i]];
        }
    }
    return arr[0];
}