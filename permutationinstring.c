class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();        

        if (len2 < len1) return false;

        unordered_map<char, int> s1map, windowmap; 

        
        for (int i = 0; i < len1; i++) {
            s1map[s1[i]]++;
            windowmap[s2[i]]++;
        }

        if (s1map == windowmap) return true;

        
        for (int i = len1; i < len2; i++) {
            windowmap[s2[i]]++;              

            char outgoing = s2[i - len1];
            windowmap[outgoing]--;          
            if (windowmap[outgoing] == 0)
                windowmap.erase(outgoing);   

            if (s1map == windowmap) return true;
        }

        return false;
    }
};