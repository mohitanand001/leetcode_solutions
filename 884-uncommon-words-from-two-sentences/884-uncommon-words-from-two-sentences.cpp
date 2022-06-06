class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
     
        string word = "";
        map<string, int> m1, m2;
        
        s1 += " ";
        s2 += " ";
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] == ' ')
            {
                m1[word]++;
                word = "";
            }
            else
            {
                word = word + s1[i];
            }
        }
        
        word = "";
        for(int i = 0; i < s2.size(); i++)
        {
            if(s2[i] == ' ')
            {
                m2[word]++;
                word = "";
            }
            else
            {
                word = word + s2[i];
            }
        }
        
        vector<string> ans;
        for(auto wrd: m1)
        {
            if(wrd.second == 1 and m2.find(wrd.first) == m2.end())
            {
                ans.push_back(wrd.first);
            }
        }
        
        for(auto wrd: m2)
        {
            if(wrd.second == 1 and m1.find(wrd.first) == m1.end())
            {
                ans.push_back(wrd.first);
            }
        }
        
        return ans;
    }
};