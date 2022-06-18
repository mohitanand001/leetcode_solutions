class Solution {
public:
    int min_cost_climb(int i, vector<int> &cost, vector<int> &dp)
    {
        if(i == cost.size())
        {
            return 0;    
        }
        
        if(i > cost.size())
            return 10000;
        
        if(dp[i] != -1)
            return dp[i];
        
        int choice_1 = cost[i] + min_cost_climb(i + 1, cost, dp);
        int choice_2 = cost[i] + min_cost_climb(i + 2, cost, dp);
        
        dp[i] = min(choice_1, choice_2);
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp (cost.size(), -1);
        int min_ = min_cost_climb(0, cost, dp);
        min_ = min(min_, min_cost_climb(1, cost, dp));
        
        return min_;
        
    }
};