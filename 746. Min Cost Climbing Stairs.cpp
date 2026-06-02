class Solution {
public:
    int min(int a , int b){
        if(a>b){
            return b;
        }
        else{
            return a;
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> steps(cost.size(), 0);
        steps[0]=cost[0];
        steps[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            steps[i]=min(steps[i-1], steps[i-2])+cost[i];
        }
        return min(steps[steps.size()-1], steps[steps.size()-2]);
    }
};