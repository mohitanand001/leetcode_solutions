class Solution {
public:
    bool found_in(const string& s, const set<char> &st)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(st.find(s[i]) == st.end() and st.find(tolower(s[i])) == st.end())
                return false;
        }
        
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
  
        vector<string> ans;
        
        set<char> r1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> r2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> r3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        for(int i = 0; i < words.size(); i++)
        {
            if(found_in(words[i], r1) or found_in(words[i], r2) or found_in(words[i], r3))
            {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};