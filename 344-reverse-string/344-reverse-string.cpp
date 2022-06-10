class Solution {
public:
    int i=0;
    void reverseString(vector<char>& s) 
    {
        
        
        int n = s.size() - 1;
        char temp = s[i];
        s[i] = s[n-i];
        s[n-i] = temp;
        i++;
        if(i <= (n/2))
        {
            reverseString(s);
        }
        
            
    }
};