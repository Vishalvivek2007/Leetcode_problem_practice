class Solution {
  public:
      void solve(vector<int>& candidates, int target, int index,
                 vector<int>& current, vector<vector<int>>& ans) {
  
          // Found a valid combination
          if (target == 0) {
              ans.push_back(current);
              return;
          }
  
          for (int i = index; i < candidates.size(); i++) {
  
              // Skip duplicates
              if (i > index && candidates[i] == candidates[i - 1])
                  continue;
  
              // No point continuing since array is sorted
              if (candidates[i] > target)
                  break;
  
              current.push_back(candidates[i]);
              solve(candidates, target - candidates[i], i + 1, current, ans);
              current.pop_back();
          }
      }
  
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(), candidates.end());
  
          vector<vector<int>> ans;
          vector<int> current;
  
          solve(candidates, target, 0, current, ans);
  
          return ans;
      }
  };