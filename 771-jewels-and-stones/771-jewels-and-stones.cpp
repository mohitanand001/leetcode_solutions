class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int sum=0;
        unordered_map<char,int> m;
        int a= jewels.length();
        int b=stones.length();
        for(int i=0;i<b;i++)
        {
            int val= stones[i];
            m[val]++;
        }
        for(int i=0;i<a;i++)
        {
            char key = jewels[i];
            if(m.find(key) != m.end())
                sum+= m[key];
        }
         return sum;       
    }
};