class Solution {
  public:
      vector<int> findRedundantConnection(vector<vector<int>>& edge) {
          int n=edge.size();
          unordered_map<int , int> map;
          for(int i=0;i<n;i++){
              if(map[edge[i][1]]){
                  return {edge[i][0] , edge[i][1]};
              }
              else{
                  map[edge[i][1]]=edge[i][0];
              }
          }
          return {edge[0][0] , edge[0][1]};
      }
  };