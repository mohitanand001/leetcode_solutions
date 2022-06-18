class Solution {
public:
    int get_trib(int n, vector<int> &dp)
    {
        if(n == 0)
            return 0;
        
        if(n == 1 or n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = get_trib(n - 3, dp) + get_trib(n - 2, dp) + get_trib(n - 1, dp);
        
        return dp[n];
        
    }
    
    int tribonacci(int n) {
        
        vector<int> dp (n + 1, -1);
        
        return get_trib(n, dp);
    }
};