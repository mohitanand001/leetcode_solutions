class Solution {
public:
    int minimumSum(int num) {
        
        vector<int> vec;
        
        while(num)
        {
            vec.push_back(num % 10);
            num = num / 10;
        }
        
        sort(vec.begin(), vec.end());
        
        return vec[0] * 10 + vec[2] + vec[1] * 10 + vec[3];
    }
};