class Solution 
{
public:
    int m,sum=0;
    int addDigits(int num) 
    { 
        if(num==0)
            return 0;
        
        int sum = 0;
        
        while(num)
        {
            m= num%10;
            sum+=m;
            num=num/10;
        }
    
        if(sum>9)
        {
            sum = addDigits(sum);
        }
        return sum;
    }
};