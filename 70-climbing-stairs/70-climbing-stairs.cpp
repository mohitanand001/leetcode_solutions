class Solution {
public:
    int nways(int i, int n, vector<int> &dp)
    {
        if(i == n)
            return 1;
        
        if(i > n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = nways(i + 1, n, dp) + nways(i + 2, n, dp);
    }
    
    int climbStairs(int n) {
        
        vector<int> dp (n + 1, -1);
        
        return nways(0, n, dp);
    }
};