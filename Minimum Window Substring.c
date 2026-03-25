class Solution {
public:
    
    string minWindow(string s, string t) {
        
        unordered_map<char, int > h1,h2;
        for(char c: t){
            h2[c]++;
        }
        int len=h2.size();
        int formed=0;

        int left =0, right=0, minlen=INT_MAX,start=0;
        while(right<s.length()){
            h1[s[right]]++;
            if(h2.count(s[right])&& h1[s[right]]==h2[s[right]]){
                formed++;
            }

            while(formed==len){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                h1[s[left]]--;
                if(h2.count(s[left])&& h1[s[left]]<h2[s[left]]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minlen==INT_MAX ? "":s.substr(start, minlen);
    }
};