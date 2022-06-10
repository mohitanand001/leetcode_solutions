class Solution {
public:
    bool is_vowel(const char &c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' \
               or c == 'A' or c == 'E' or c == 'I' or c== 'O' or c == 'U');
            
    }
    
    void reverse(int i, int j, string &s)
    {
        if(i > j)
            return;
        
        if(is_vowel(s[i]) and is_vowel(s[j]))
        {
            swap(s[i], s[j]);
            reverse(i + 1, j - 1, s);
        }
        else
        {
            if(!is_vowel(s[i]))
                i++;
            if(!is_vowel(s[j]))
                j--;
            
            reverse(i, j, s);
        }
    }
    
    
    string reverseVowels(string s) {
                
        reverse(0, s.size() - 1, s);
        return s;
    }
};