class Solution {
  public:
      int ladderLength(string start, string final, vector<string>& arr) {
          if (start == final) return 1;
  
          unordered_set<string> words(arr.begin(), arr.end());
  
          if (!words.count(final)) return 0;
  
          queue<pair<string, int>> q;
          q.push({start, 1});
  
          words.erase(start);
  
          while (!q.empty()) {
              string temp = q.front().first;
              int steps = q.front().second;
              q.pop();
  
              if (temp == final) return steps;
  
              for (int i = 0; i < temp.length(); i++) {
                  char original = temp[i];
  
                  for (char c = 'a'; c <= 'z'; c++) {
                      temp[i] = c;
  
                      if (words.count(temp)) {
                          q.push({temp, steps + 1});
  
                          // Mark visited immediately
                          words.erase(temp);
                      }
                  }
  
                  temp[i] = original;
              }
          }
  
          return 0;
      }
  };