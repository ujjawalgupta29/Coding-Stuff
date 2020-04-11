class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> prev(n, 1);
        vector<int> curr(n,0);
        
        for(int j=0; j<m-1; j++)
        {
            curr[0] = 1;
            for(int i=1; i<n; i++)
            {
                curr[i] = curr[i-1] + prev[i];
            }
            swap(prev, curr);
        }
        
        return prev[n-1];
    }
};