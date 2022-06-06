class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        map<string, int> mp1, mp2;
        string curr = "";
        for(int i = 0; i < words1.size(); i++)
            mp1[words1[i]]++;
        
        for(int i = 0; i < words2.size(); i++)
        {
            mp2[words2[i]]++;
        }
        
        int ans = 0;
        for(auto wrd: mp1)
        {
            if(wrd.second == 1 and mp2[wrd.first] == 1)
                ans++;
        }
        
        return ans;
    }
};