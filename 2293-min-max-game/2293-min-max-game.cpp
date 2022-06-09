class Solution {
public:
    
//     void solve(vector<int> nums)
//     {
//         if(i > j)
//             return;
        
//         for(int k = i; k <= j; k++)
//         {
//             if(k)
//         }
//     }
    
    int minMaxGame(vector<int>& nums) {

        vector<int> tmp1 = nums;
        vector<int> tmp2;
        while(tmp1.size() > 1)
        {
            tmp2.clear();
            
            for(int i = 0, k = 0; i < tmp1.size(); i+=2, k+=1)
            {
                if(k % 2 == 0)
                {
                    tmp2.push_back(min(tmp1[i], tmp1[i + 1]));
                }
                else
                {
                    tmp2.push_back(max(tmp1[i], tmp1[i + 1]));
                }
            }
            
            tmp1 = tmp2;
        }
        
        return tmp1[0];
        
    }
};