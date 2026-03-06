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
    int characterReplacement(string s, int k) {
        int len=s.length();
        int ans=0,maxcharcount=0;
        char maxchar;
        unorderd_map< char,int> mp;
        int l=0,r=0;
        while(r!=len){
            mp[s[r]]++;
            if(mp[s[r]]>maxcharcount){
                maxcharcount=mp[s[r]];
                maxchar=s[r];
            }
            int temp=r-l+1-maxcharcount;
            if(temp>k){
                ans=max(ans,r-l+1);
                while(s[l]==maxchar){
                    l++;
                }
                l++;
                r=l;
                mp.clear();
                continue;
            }
            r++;
        }
        return ans;        
    }
};