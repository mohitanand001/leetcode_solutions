class Solution {
public:
    bool is_vowel(const char &c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' \
               or c == 'A' or c == 'E' or c == 'I' or c== 'O' or c == 'U');
            
    }
    
    string reverseVowels(string s) {
     
        int i = 0, j = s.size() - 1;
        
        while(i <= j)
        {
            if(is_vowel(s[i]) and is_vowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else
            {
                if(!is_vowel(s[i]))
                    i++;
                if(!is_vowel(s[j]))
                    j--;
            }
        }
        
        return s;
    }
};