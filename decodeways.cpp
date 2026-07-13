class Solution {
  public:
      vector<int> dp;
  
      bool isValid(string i){
          if(i[0]=='0'){
              return false;
          }
          int temp = stoi(i);
          return temp >= 1 && temp <= 26;
      }
  
      int recursive(string s){
          if(s.length()==0){
              return 1;
          }
  
          if(dp[s.length()] != -1){
              return dp[s.length()];
          }
  
          int count = 0;
  
          if(isValid(s.substr(0,1))){
              count += recursive(s.substr(1));
          }
  
          if(s.length()>1 && isValid(s.substr(0,2))){
              count += recursive(s.substr(2));
          }
  
          return dp[s.length()] = count;
      }
  
      int numDecodings(string s) {
          dp.resize(s.length()+1,-1);
          return recursive(s);
      }
  };