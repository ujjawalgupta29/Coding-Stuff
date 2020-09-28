class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int k, int n, int num, vector<int> &temp)
    {
        if(n == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(k < 0 || n < 0)
            return;
        
        for(int i=num; i<=9; i++)
        {
            temp.push_back(i);
            solve(k-1, n-i, i+1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < 1)
            return ans;
        
        vector<int> temp;
        solve(k, n, 1, temp);
        return ans;
    }
};