class Solution {
public:
    int countGoodSubstrings(string s) {
        
        if(s.size() < 3)
            return 0;
        
        int cnt = 0;
        
        for(int i = 1; i < s.size() - 1; i++)
        {
            if((s[i - 1] != s[i]) and (s[i] != s[i + 1]) and (s[i- 1] != s[i + 1]))
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};