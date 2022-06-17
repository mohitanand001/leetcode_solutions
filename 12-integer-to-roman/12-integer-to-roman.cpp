class Solution {
public:
    string multiply_str(string &s, int times)
    {
        string res = "";
        for(int i = 1; i <= times; i++)
        {
            res = res + s;
        }
        
        return res;
    }
    
    string intToRoman(int num) {
        
        map<int, string> mp = {
            
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        
        string res = "";
        
        while(num)
        {
            int max_ = mp.rbegin()->first;
            cout << max_ << endl;
            if(num / max_)
            {
                res += multiply_str(mp[max_], num / max_);
            }
            num = num % max_;
            mp.erase(max_);
        }
        
        return res;
    }
    
    
};