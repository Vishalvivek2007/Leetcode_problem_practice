class Solution {
  public:
      void recursive(vector<string>& ans , string temp  , int left , int right){
          if(left==0 && right==0){
              ans.push_back(temp);
              return;
          }
          if(left==right){
              recursive(ans  , temp+"(", left-1 , right);
          }
          else if(left>0){
              recursive(ans , temp+"(" , left-1 , right);
              recursive(ans , temp+")" , left , right-1);
          }
          else{
              recursive(ans , temp+")" ,left , right-1);
          }
          return ;
      }
      vector<string> generateParenthesis(int n) {
          vector<string> ans;
          string str;
          recursive(ans  , str , n ,n);
          return ans; 
      }
  };
  