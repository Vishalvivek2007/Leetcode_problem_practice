class Solution {
  public:
      vector<string> findItinerary(vector<vector<string>>& tickets) {
  
          unordered_map<string, multiset<string>> mp;
  
          // Step 1: Build adjacency list
          for (int i = 0; i < tickets.size(); i++) {
              mp[tickets[i][0]].insert(tickets[i][1]);
          }
  
          // Step 2: Start from JFK
          stack<string> st;
          vector<string> path;
  
          st.push("JFK");
  
          // Step 3: Traverse
          while (!st.empty()) {
  
              string curr = st.top();
  
              if (!mp[curr].empty()) {
  
                  // Get smallest available destination
                  auto it = mp[curr].begin();
  
                  string next = *it;
  
                  // Consume this ticket
                  mp[curr].erase(it);
  
                  // Move to next airport
                  st.push(next);
  
              }
              else {
  
                  // No outgoing tickets left
                  path.push_back(curr);
                  st.pop();
  
              }
          }
  
          // Step 4: Reverse the final path
          reverse(path.begin(), path.end());
  
          return path;
      }
  };