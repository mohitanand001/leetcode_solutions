class Solution {
public:
    int mod = 1000000007;
    int tiling(int row_1, int row_2, int n, vector< vector<int> > &dp)
    {   
        // cout<<row_1<<" "<<row_2<<endl;
        
        if(row_1 == n + 1 and row_2 == n + 1)
            return 1;
        
        if(row_1 >= n + 1 or row_2 >= n + 1)
            return 0;
        
        if(dp[row_1][row_2] != -1)
            return dp[row_1][row_2];
        
        int choice_1 = 0, choice_2 = 0, choice_3 = 0, choice_4 = 0;
                
        if(row_1 == row_2)
        {
            choice_1 = tiling(row_1 + 1, row_2 + 1, n, dp);
            choice_2 = tiling(row_1 + 2, row_2 + 2, n, dp);
            choice_3 = tiling(row_1 + 2, row_2 + 1, n, dp);
            choice_4 = tiling(row_1 + 1, row_2 + 2, n, dp);
        }
        else if(row_1 > row_2)
        {
            choice_1 = tiling(row_1, row_2 + 2, n, dp);
            choice_2 = tiling(row_1 + 1, row_2 + 2, n, dp);
        }
        
        else
        {
            choice_1 = tiling(row_1 + 2, row_2, n, dp);
            choice_2 = tiling(row_1 + 2, row_2 + 1, n, dp);
        }
        
        dp[row_1][row_2] =  (((choice_1%mod + choice_2%mod)%mod + choice_3%mod)%mod + choice_4%mod)%mod;
        
        return dp[row_1][row_2];
    }
    
    int numTilings(int N) {
        vector< vector<int> > dp (N+1, vector<int> (N+1, -1));
        
        return tiling(1, 1, N, dp);
    }
};