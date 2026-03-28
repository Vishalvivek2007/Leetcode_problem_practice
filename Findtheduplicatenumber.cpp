class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        // Step 1: Detect cycle
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);

        // Step 2: Find entry point of cycle
        slow = arr[0];  // reset

        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow; // duplicate
    }
};