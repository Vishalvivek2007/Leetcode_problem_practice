class Solution {
  public:
      ListNode* reverseKGroup(ListNode* head, int k) {
          ListNode* curr = head;
          ListNode* prev = NULL;
  
          while (curr != NULL) {
              ListNode* end = curr;
  
              int temp = k - 1;
  
              while (end != NULL && temp > 0) {
                  end = end->next;
                  temp--;
              }
  
              // Fewer than k nodes remain
              if (end == NULL) {
                  if (prev != NULL)
                      prev->next = curr;
                  break;
              }
  
              ListNode* next_node = end->next;
  
              ListNode* temp1 = curr;
              ListNode* temp2 = curr->next;
  
              while (temp2 != next_node) {
                  ListNode* temp3 = temp2->next;
                  temp2->next = temp1;
                  temp1 = temp2;
                  temp2 = temp3;
              }
  
              // Connect the previous group
              if (prev != NULL)
                  prev->next = end;
              else
                  head = end;
  
              // Connect the reversed group to the remaining list
              curr->next = next_node;
  
              // Old group's head is now its tail
              prev = curr;
              curr = next_node;
          }
  
          return head;
      }
  };