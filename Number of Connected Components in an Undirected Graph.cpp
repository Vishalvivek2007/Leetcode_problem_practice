class Solution {
  public:
  
      int countComponents(int n, vector<vector<int>>& edges) {
          if(n==1){
              return 1;
          }
          unordered_map<int, vector<int>> map;
          for(int i=0;i<edges.size();i++){
              map[edges[i][0]].push_back(edges[i][1]);
              map[edges[i][1]].push_back(edges[i][0]);
          }
          int count=0;
          vector<int> visited(n , 0);
          queue<vector<int>> q;
          for(int i=0;i<n;i++){
              if(!visited[i]){
                  q.push({i ,-1});
                  while(!q.empty()){
                      int node = q.front()[0];
                      int parent = q.front()[1];
                      q.pop();
                      visited[node]=1;
                      for(int j=0;j<map[node].size();j++){
                          if(map[node][j]!= parent && !visited[map[node][j]]){
                              q.push({map[node][j]  , node});
                          }
                      }
                  }
                  count++;
              }
          }
          return count;
      }
  };
  