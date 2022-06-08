class Solution {
public:
    string reverseWords(string s) 
    {
        s+= " ";
        string temp;
        string ans;
        for(int i=0;i<s.length();i++)
        {
            temp="";
            while(s[i]!= ' ')
            {
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            ans+=temp;
            ans+=" ";
            
        }
        
        ans.pop_back();
        return ans;
    }
};