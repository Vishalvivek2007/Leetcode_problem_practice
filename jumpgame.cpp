class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=nums[0],index=0,len=nums.size();
        while(index!=len-1){
            if(max<nums[index]){
                max=nums[index];
            }
            if(max==0){
                break;
            }
            if(max>0){
                max--;
                index++;
            }
        }
        if(index!=len-1){
            return false;
        }
        else{
            return true;
        }
    }
};