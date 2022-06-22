class Solution {
public:
    int find_min(int i, int j, vector<vector<int> >& triangle, vector<vector<int> > &dp)
    {
        if(i == triangle.size() - 1)
            return triangle[i][j];
        
        if(dp[i][j] != -100555)
            return dp[i][j];
        
        int choice_1, choice_2;
        
        choice_1 = find_min(i + 1, j, triangle, dp);
        choice_2 = find_min(i + 1, j + 1, triangle, dp);
        
        return dp[i][j] = min(choice_1, choice_2) + triangle[i][j];
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int> > dp (triangle.size(), vector<int> (triangle.back().size(), -100555));
        
        return find_min(0, 0, triangle, dp);
    }
};