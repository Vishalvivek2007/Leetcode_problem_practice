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
    int largestRectangleArea(vector<int>& arr) {
        if(arr.empty()){
            return 0;
        }
        stack<int> height;
        stack<int> index;
        int maxarea=-1;
        for(int i=0;i<arr.size();i++){
            if(height.empty()|| arr[i]>=height.top()){
                height.push(arr[i]);
                index.push(i);
            }
            else{
                int lastpop=0;
                while(!height.empty() && height.top()>arr[i]){
                    maxarea=max(maxarea, (i-index.top())*height.top());
                    lastpop=index.top();
                    index.pop();
                    height.pop();
                }
                height.push(arr[i]);
                index.push(lastpop);
            }
        }
        while(!height.empty()){
            maxarea=max(maxarea, (arr.size()-index.top())*height.top());
            index.pop();
            height.pop();
        }
        return maxarea;
    }
};