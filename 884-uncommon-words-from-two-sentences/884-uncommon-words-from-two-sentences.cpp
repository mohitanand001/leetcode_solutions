class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        vector<string>ans;
        vector<string>s;
        string temp;
        unordered_map<string,int> m;
        
        s1 = s1 + " ";
        s2 = s2 + " ";
        for(int i=0;i<s1.length();i++)
        {
            temp="";
            while(s1[i]!= ' ')
            {
                temp+=s1[i];
                i++;
            }
            ans.push_back(temp);
        }
                  
        
       for(int i=0;i<s2.length();i++)
        {
            temp="";
            while(s2[i]!= ' ')
            {
                temp+=s2[i];
                i++;
            }
            ans.push_back(temp);
        }
        
       for(auto& a :ans)
       {
            m[a]++;
       }
       
        // return s;
        
        for(auto& e: m)
        {
            if(e.second== 1)
                s.push_back(e.first);
        }
        
        return s;
    }
};