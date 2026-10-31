class Solution {
  public:
      bool mergeTriplets(vector<vector<int>>& triples, vector<int>& target) {
          vector<int> curr = {-1, -1, -1};
  
          for(auto &t : triples) {
              if(t[0] > target[0] ||
                 t[1] > target[1] ||
                 t[2] > target[2]) {
                  continue;
              }
  
              curr[0] = max(curr[0], t[0]);
              curr[1] = max(curr[1], t[1]);
              curr[2] = max(curr[2], t[2]);
  
              if(curr == target) {
                  return true;
              }
          }
  
          return false;
      }
  };