class Solution {
public:
    
    void solve(int n, int k, int num, vector<int> &res)
    {
        if(n == 0)
        {
            res.push_back(num);
            return;
        }
        
        int last_dig = num % 10;
        
        if(last_dig + k < 10)
            solve(n-1, k, num*10 + last_dig + k, res);
        
        if(last_dig - k >= 0 && k != 0)
            solve(n-1, k, num*10 + last_dig - k, res);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        if(n == 1)
            res.push_back(0);
            
        for(int i=1; i<=9; i++)
        {
            solve(n-1, k, i, res);
        }
        return res;
    }
};