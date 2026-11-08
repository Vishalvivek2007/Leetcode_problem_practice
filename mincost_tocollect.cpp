class Solution {
  public:
      struct Compare {
          bool operator()(const vector<int>& a, const vector<int>& b) const {
              return a[0] > b[0];
          }
      };
  
      int findParent(vector<int>& parent, int x) {
          if (parent[x] != x)
              parent[x] = findParent(parent, parent[x]);
  
          return parent[x];
      }
  
      int minCostConnectPoints(vector<vector<int>>& points) {
          int n = points.size();
  
          priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
  
          for (int i = 0; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  int dist = abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);
  
                  heap.push({dist, i, j});
              }
          }
  
          vector<int> parent(n);
          for (int i = 0; i < n; i++)
              parent[i] = i;
  
          int count = 0, total = 0;
  
          while (count != n - 1) {
              int dist = heap.top()[0];
              int left = heap.top()[1];
              int right = heap.top()[2];
  
              heap.pop();
  
              int p1 = findParent(parent, left);
              int p2 = findParent(parent, right);
  
              if (p1 == p2)
                  continue;
  
              parent[p1] = p2;
  
              total += dist;
              count++;
          }
  
          return total;
      }
  };