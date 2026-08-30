class Solution {
  public:
      int leastInterval(vector<char>& tasks, int n) {
  
          unordered_map<char, int> mp;
  
          for(char c : tasks) {
              mp[c]++;
          }
  
          priority_queue<int> maxHeap;
  
          for(auto x : mp) {
              maxHeap.push(x.second);
          }
  
          queue<pair<int, int>> q;
          // {remaining frequency, time when it can be used again}
  
          int time = 0;
  
          while(!maxHeap.empty() || !q.empty()) {
  
              time++;
  
              // Put cooled-down tasks back into heap
              if(!q.empty() && q.front().second == time) {
                  maxHeap.push(q.front().first);
                  q.pop();
              }
  
              // Execute most frequent task
              if(!maxHeap.empty()) {
  
                  int freq = maxHeap.top();
                  maxHeap.pop();
  
                  freq--;
  
                  if(freq > 0) {
                      q.push({freq, time + n + 1});
                  }
              }
          }
  
          return time;
      }
  };