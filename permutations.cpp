class Solution {
  public:
      void recursive(vector<int>& nums , vector<vector<int>>& ans , vector<bool>& visited , vector<int>& temp){
          for(int i=0;i<nums.size();i++){
              if(visited[i]){
                  continue;
              }
              visited[i]=true;
              temp.push_back(nums[i]);
              if(temp.size()==nums.size()){
                  ans.push_back(temp);
              }
              else{
                  recursive(nums , ans , visited , temp);
              }
              temp.pop_back();
              visited[i]=false;
          }
          return;
      }
  
      vector<vector<int>> permute(vector<int>& nums) {
          vector<bool> visited(nums.size() , false);
          vector<vector<int>> ans;
          vector<int> temp;
          recursive(nums , ans  , visited,temp);
          return ans;
      }
  };