class Solution {
public:
    
    double power(double x, int n)
    {
        double ans = 1;
        while(n != 0)
        {
            if(n&1 && n > 0)
            {
                ans = ans * x;
            }
            
            else if(n&1 && n < 0)
            {
                ans = ans / x;
            }
            
            n = n / 2;
            x = x*x;
        }
        
        return ans;
    }
    
    double myPow(double x, int n) {
        
        double res = power(x, n);

        return res;
    }
};