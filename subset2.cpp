class Solution {
  public:
      void recursive(vector<int>& nums, vector<vector<int>>& ans,
                     vector<int>& temp, int i) {
  
          if(i == nums.size()) {
              ans.push_back(temp);
              return;
          }
  
          // Find the end of the duplicate group
          if(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
  
              int j = i;
  
              while(j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                  j++;
              }
              j++;
  
              // Take 0, 1, 2, ... copies
              for(int k = i; k < j; k++) {
                  recursive(nums, ans, temp, j);
                  temp.push_back(nums[i]);
              }
  
              // Take all copies
              recursive(nums, ans, temp, j);
  
              // Remove all added copies
              for(int k = i; k < j; k++) {
                  temp.pop_back();
              }
          }
  
          else {
              // Don't take
              recursive(nums, ans, temp, i + 1);
  
              // Take
              temp.push_back(nums[i]);
              recursive(nums, ans, temp, i + 1);
              temp.pop_back();
          }
      }
  
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  
          sort(nums.begin(), nums.end());
  
          vector<vector<int>> ans;
          vector<int> temp;
  
          recursive(nums, ans, temp, 0);
  
          return ans;
      }
  };