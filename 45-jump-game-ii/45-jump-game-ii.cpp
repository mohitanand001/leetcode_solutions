class Solution {
public:
    int min_jumps(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i >= nums.size() - 1)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        long ans = nums.size() + 1;
        for(int j = i + 1; j <= i + nums[i]; j++)
        {
            ans = min(ans, 1L*min_jumps(j, nums, dp));
        }
        
        dp[i] = ans + 1;
        return ans + 1;
    }
    
    int jump(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return 0;
        
        vector<int> dp (nums.size(), -1);
        
        return min_jumps(0, nums, dp);
    }
};