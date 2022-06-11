class Solution {
public:
    string digitSum(string s, int k) {
        
        
        if(s.size() <= k)
            return s;
        
        string temp = "";
        int sm = 0;
        
        for(int i = 0, j = 1; i < s.size(); i++, j++)
        {
            if(j % k == 0)
            {
                sm = sm + (s[i] - '0');
                temp = temp + to_string(sm);
                sm = 0;
            }
            else
            {
                sm = sm + (s[i] - '0');
            }
        }
        
        if(s.size() % k)
        {
           temp = temp + to_string(sm);
                 
        }
        
        return digitSum(temp, k);
    }
};