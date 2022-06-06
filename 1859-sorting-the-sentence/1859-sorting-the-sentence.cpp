class Solution {
public:
string sortSentence(string s) 
    {

        
        int n=1;
        int c= s.length();
    
        for(int i = 0 ; i < c; i++)
        {
            if(s[i]== ' ')
                n++;
        }
    
        pair<int,string>pa[n + 1];
    
        // return "ans";
        s = s + " ";
        string ans = "";
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ans.pop_back();
                pa[j++] = make_pair(s[i-1], ans);  
                ans = "";
            }
            else
            {
                ans = ans + s[i];
            }
        }
    
        sort(pa,pa+n);
        string res = "";
        for(int i=0; i < n;i++)
        {
            res = res + pa[i].second;
            if(i != n - 1)
                res+= " ";            
        }
        
        return res;
    
    }
};