class Solution {
public:
    
    bool possible(int i, vector<int> &m, vector<int>& sms, int target)
    {
        if(i == m.size())
        {
            for(int k = 0; k < sms.size(); k++)
                if(sms[k] != target)
                    return false;
            
            return true;
        }
        
        bool ans = false;
        
        for(int k = 0; k < sms.size(); k++)
        {
            if(sms[k] + m[i] <= target)
            {
                sms[k] +=m[i];
                if(possible(i + 1, m, sms, target))
                    return true;

                sms[k] -=m[i];
                
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& m) {
        
        sort(m.begin(), m.end(), greater<int>());

        int sm = 0;
        for(int i = 0; i < m.size(); i++)
            sm += m[i];
        
        
        if(sm % 4 != 0)
            return false;
        
        vector<int> sms (4, 0);
        
        return possible(0, m, sms, sm / 4);
    }
};