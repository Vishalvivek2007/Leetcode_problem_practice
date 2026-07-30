class Solution {
  public:
      void recursive(vector<vector<int>>& ans, vector<int>& temp,
                     vector<int>& candidates, int target, int index) {
  
          if (target == 0) {
              ans.push_back(temp);
              return;
          }
  
          if (target < 0)
              return;
  
          for (int i = index; i < candidates.size(); i++) {
              temp.push_back(candidates[i]);
  
              // i instead of i+1 because we can reuse the same element
              recursive(ans, temp, candidates, target - candidates[i], i);
  
              temp.pop_back(); // backtrack
          }
      }
  
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> ans;
          vector<int> temp;
  
          recursive(ans, temp, candidates, target, 0);
  
          return ans;
      }
  };