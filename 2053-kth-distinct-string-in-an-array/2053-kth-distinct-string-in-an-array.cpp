class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string,int>m;
        vector<string>v;
        string a= "";
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            m[arr[i]]++;    
        }
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int n = m[arr[i]];
            if(n == 1)
                v.push_back(arr[i]);      
        }
        if(v.size() < k)
            return a;
        return v[k-1]; 
    }
};