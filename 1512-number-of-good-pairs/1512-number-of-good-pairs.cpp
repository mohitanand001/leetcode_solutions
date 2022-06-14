class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int pairs = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pairs+= m[nums[i]];
            
            m[nums[i]]++;
        }
        
        return pairs;
    }
};