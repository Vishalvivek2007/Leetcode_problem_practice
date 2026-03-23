class Solution {
public:
    int max(int a, int b){
        if(a>b){
            return a;
        }
        else{
            return b;
        }
    }
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int p1=0,p2=k-1;
        int maxsum=0,sum=0;
        for(int i=0;i<=p2;i++){
            sum+=arr[i];
        }
        maxsum=sum;
        vector<int> v;
        v.push_back(maxsum);

        
        return v;
    }
};