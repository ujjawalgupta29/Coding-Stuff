class Solution {
public:
    long mod = 1e9 + 7;
    int numOfWays(int n) {
        long f_121 = 6, f_123 = 6, s_121, s_123;
        
        for(int i=1; i<n; i++)
        {
            s_121 = f_121*3 + f_123*2;
            s_123 = f_121*2 + f_123*2;
            
            f_121 = s_121 % mod;
            f_123 = s_123 % mod;
        }
        
        return (f_121 + f_123) % mod;
    }
};