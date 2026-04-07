class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(auto node : lists){
            if(node) pq.push(node);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* minimum = pq.top();
            pq.pop();

            if(head == NULL){
                head = minimum;
                tail = minimum;
            } else {
                tail->next = minimum;
                tail = minimum;
            }

            if(minimum->next){
                pq.push(minimum->next);
            }
        }

        return head;
    }
};