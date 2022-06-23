class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        if(n == 0)
            return 0;
        
        for(int i = 0; i < h; i++)
        {
            int matches = 0;
            for(int j = 0; j < n and i + j < h; j++)
            {
                if(needle[j] == haystack[i + j])
                {
                    matches++;
                }
            }
            
            if(matches  == n)
                return i;
        }
        
        return -1;
    }
};