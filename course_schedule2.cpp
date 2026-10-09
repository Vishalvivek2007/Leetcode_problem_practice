class Solution {
  public:
      bool complete(int i, vector<vector<int>>& graph,
                    vector<int>& visited, vector<int>& path) {
  
          if (visited[i] == 1) return false;
          if (visited[i] == 2) return true;
  
          visited[i] = 1;
  
          for (int j : graph[i]) {
              if (!complete(j, graph, visited, path))
                  return false;
          }
  
          visited[i] = 2;
          path.push_back(i);
          return true;
      }
  
      vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> graph(numCourses);
  
          for (auto& p : prerequisites) {
              graph[p[1]].push_back(p[0]);
          }
  
          vector<int> visited(numCourses, 0);
          vector<int> path;
  
          for (int i = 0; i < numCourses; i++) {
              if (visited[i] == 0) {
                  if (!complete(i, graph, visited, path))
                      return {};
              }
          }
  
          reverse(path.begin(), path.end());
          return path;
      }
  };