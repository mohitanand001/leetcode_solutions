class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
     
        map<string, int> mp;
        
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        
        for(int i = 0, j = 0; i < arr.size(); i++)
        {
            
            if(mp[arr[i]] == 1)
                j++;
            
            if(j == k)
                return arr[i];
            
        }
        
        return "";
    }
};