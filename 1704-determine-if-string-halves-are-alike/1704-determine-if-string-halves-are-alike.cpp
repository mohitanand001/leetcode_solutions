class Solution {
public:
    bool halvesAreAlike(string s) {
        
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int first_half = 0, second_half = 0;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            if(i < n / 2)
            {
                if(vowels.find(s[i]) != vowels.end())
                {
                    first_half++;
                }
            }
            
            else
            {
                if(vowels.find(s[i]) != vowels.end())
                {
                    second_half++;
                }
                
            }
        }
        
        return first_half == second_half;
    }
};