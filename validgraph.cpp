class Solution {
  public:
      bool validTree(int n, vector<vector<int>>& edges) {
          if (edges.size() == 0 && n > 1) return false;
          if (edges.size() == 0 && n == 1) return true;
  
          unordered_map<int, vector<int>> adj;
          unordered_map<int, int> check;
          queue<pair<int, int>> q;
  
          for (int i = 0; i < edges.size(); i++) {
              adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
          }
  
          q.push({edges[0][0], -1});
          check[edges[0][0]]++;
  
          while (!q.empty()) {
              int node = q.front().first;
              int parent = q.front().second;
              q.pop();
  
              for (int neighbor : adj[node]) {
                  if (neighbor == parent) {
                      continue;
                  }
  
                  if (check.contains(neighbor)) {
                      return false;
                  }
  
                  check[neighbor]++;
                  q.push({neighbor, node});
              }
          }
  
          return check.size() == n;
      }
  };