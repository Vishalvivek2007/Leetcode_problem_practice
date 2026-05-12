class Solution {
public:
    int jump(vector<int>& arr) {
        int i = 0, n = arr.size(), count = 0;
        if (n <= 1) return 0;
        
        while (i < n - 1) {
            if (i + arr[i] >= n - 1) {
                return count + 1;
            }
            
            int max_reach = -1, next_index = -1;
            int jump_limit = min(i + arr[i], n - 1);
            
            for (int index = i + 1; index <= jump_limit; index++) {
                if (index + arr[index] > max_reach) {
                    max_reach = index + arr[index];
                    next_index = index;
                }
            }
            
            i = next_index;
            count++;
        }
        return count; 
    }
};