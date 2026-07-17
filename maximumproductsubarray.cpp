class Solution {
  public:
      int max2(int a, int b){
          if(a>b){
              return a;
          }
          else{
              return b;
          }
      }
      int max3(int a, int b, int c){
          if(a>=b && a>=c){
              return a;
          }
          else if(b>=a && b>=c){
              return b;
          }
          else{
              return c;
          }
      }
      int min3(int a , int b, int c){
          if(a<=b && a<=c){
              return a;
          }
          else if(b<=a && b<=c){
              return b;
          }
          else{
              return c;
          }
      }
      int maxProduct(vector<int>& nums) {
          int res=nums[0];
          for(int i=0;i<nums.size();i++){
              if(nums[i]>res){
                  res=nums[i];
              }
          }
          int max=1, min=1;
          for(int i=0;i<nums.size();i++){
              if(nums[i]==0){
                  max=1;
                  min=1;
                  continue;
              }
              int temp = max*nums[i];
              max=max3(max*nums[i], nums[i]*min, nums[i]);
              min=min3(temp, nums[i]*min,nums[i] );
              res =max2(res,max);
          }
          return res;
      }
  };