class Solution {
  public:
      vector<vector<string>> ans;
      vector<string> curr;
  
      bool isPalindrome(string s, int l, int r) {
          while (l < r) {
              if (s[l] != s[r]) return false;
              l++;
              r--;
          }
          return true;
      }
  
      void backtrack(string& s, int start) {
          if (start == s.size()) {
              ans.push_back(curr);
              return;
          }
  
          for (int i = start; i < s.size(); i++) {
              if (isPalindrome(s, start, i)) {
                  curr.push_back(s.substr(start, i - start + 1));
  
                  backtrack(s, i + 1);
  
                  curr.pop_back();
              }
          }
      }
  
      vector<vector<string>> partition(string s) {
          backtrack(s, 0);
          return ans;
      }
  };