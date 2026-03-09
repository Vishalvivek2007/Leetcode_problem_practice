class Solution {
public: 
    int calculate(int n){
        int sum = 0;

        while(n > 0){
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_map<int,int> mp;

        while(true){

            if(mp[n]){
                return false;
            }

            mp[n] = 1;

            n = calculate(n);

            if(n == 1){
                return true;
            }
        }
    }
};