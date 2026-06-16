class Solution {
  public:
      int max(int  a, int b){
          if(a>b){
              return a;
          }
          else{
              return b;
          }
      }
      int rob(vector<int>& nums) {
          if(nums.size()==1){
              return nums[0];
          }
          else if( nums.size()==2){
              return max(nums[1] , nums[0]);
          }
          vector<int> ans1,ans2;
          bool fronttake=false;
          for(int i=0;i<nums.size()-1;i++){
              if(i==0){
                  ans1.push_back(nums[i]);
              }
              else if(i==1){
                  ans1.push_back(max(nums[i] , nums[i-1]));
              }
              else{
                  ans1.push_back(max(ans1[i-1] , ans1[i-2]+nums[i]));
              }
          }
  
          for(int i=1;i<nums.size();i++){
              if(i==1){
                  ans2.push_back(nums[i]);
              }
              else if(i==2){
                  ans2.push_back(max(nums[i] , nums[i-1]));
              }
              else{
                  ans2.push_back(max(ans2[i-2] , ans2[i-3]+nums[i]));
              }
          }
          return max(ans1[nums.size()-2] , ans2[nums.size()-2]);
      }
  };