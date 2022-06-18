class Solution {
public:
    int decodes(int i, string &s, vector<int> &dp)
    {
        if(i == s.size())
        {
            return 1;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        int curr = s[i] - '0';
        
        if(curr == 0)
            return 0;
        
        int ways1 = decodes(i + 1, s, dp);
        int ways2 = 0;
        if(i + 1 < s.size())
        {
            if(((s[i] - '0')*10 + (s[i + 1] - '0')) <= 26)
            {
                ways2 = decodes(i + 2, s, dp);
            }
        }
        
        dp[i] = ways1 + ways2;
        
        return dp[i];
    }
    
    int numDecodings(string s) {
        
        vector<int> dp (s.size(), -1);
        return decodes(0, s, dp);
    }
};