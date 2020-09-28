class Solution {
public:
    
    unordered_map<int, int> dp;
    
    int solve(int n)
    {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp.count(n))
            return dp[n];
        
        int res = INT_MAX;
        
        if(n%2 == 0)
            res = min(res, 1 + solve(n/2));
        
        if(n%3 == 0)
            res = min(res, 1 + solve(n/3));
        
        if((n-1)%2 == 0 || (n-1)%3 == 0)
            res = min(res, 1+solve(n-1));
        
        if((n-2)%3 == 0)
            res = min(res, 2+solve(n-2));
        
        return dp[n] = res;
    }
    
    int minDays(int n) {
        
        return solve(n);
    }
};