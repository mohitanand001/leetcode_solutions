class Solution {
public:
    bool has_pref(string &word, string &pref)
    {
        int i;
        for(i = 0; i < pref.size() and i < word.size(); i++)
        {
            if(pref[i] != word[i])
                return false;
        }
        
        if(i != pref.size())
            return false;
        return true;
    }
    
    int prefixCount(vector<string>& words, string pref) {
        
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(has_pref(words[i], pref))
                count++;
        }
        
        return count;
    }
};