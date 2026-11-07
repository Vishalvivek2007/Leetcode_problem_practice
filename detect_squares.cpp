class DetectSquares {
  public:
      unordered_map<int, unordered_map<int, int>> pts;
  
      DetectSquares() {}
      
      void add(vector<int> point) {
          pts[point[0]][point[1]]++;
      }
      
      int count(vector<int> point) {
          int x1 = point[0], y1 = point[1];
          int ans = 0;
  
          for (auto& [y2, count_p2] : pts[x1]) {
              int d = abs(y2 - y1);
              if (d == 0) continue;
  
              
              if (pts.count(x1 + d)) {
                  if (pts[x1 + d].count(y1) && pts[x1 + d].count(y2)) {
                      ans += count_p2 * pts[x1 + d][y1] * pts[x1 + d][y2];
                  }
              }
  
              
              if (pts.count(x1 - d)) {
                  if (pts[x1 - d].count(y1) && pts[x1 - d].count(y2)) {
                      ans += count_p2 * pts[x1 - d][y1] * pts[x1 - d][y2];
                  }
              }
          }
          return ans;
      }
  };