class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n, vector<int>(n,n));
        
        for(auto v : mines)
        {
            mat[v[0]][v[1]] = 0;
        }
        
        int max_plus = 0;
        for(int i=0; i<n; i++)
        {
            int l=0, r=0, d=0, u=0;
            
            for(int j=0; j<n; j++)
            {
                mat[i][j] = min(mat[i][j], l = (mat[i][j] == 0) ? 0 : l+1);    
            }
            
            for(int j=n-1; j>=0; j--)
            {
                mat[i][j] = min(mat[i][j], r = (mat[i][j] == 0) ? 0 : r+1);    
            }
            
            for(int j=0; j<n; j++)
            {
                mat[j][i] = min(mat[j][i], u = (mat[j][i] == 0) ? 0 : u+1);    
            }
            
            for(int j=n-1; j>=0; j--)
            {
                mat[j][i] = min(mat[j][i], d = (mat[j][i] == 0) ? 0 : d+1);    
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                max_plus = max(max_plus, mat[i][j]);
        }
        
        return max_plus;
    }
};