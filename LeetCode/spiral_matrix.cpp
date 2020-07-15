class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size();
        if(m == 0)
            return res;
        int n = mat[0].size();
        
        int k=0, l=0;
        
        while(k < m && l < n)
        {
            for(int i=l; i<n; i++)
            {
                res.push_back(mat[k][i]);
            }
            k++;
            
            for(int i=k; i<m; i++)
            {
                res.push_back(mat[i][n-1]);
            }
            n--;
            
            if(k < m)
            {
                for(int i=n-1; i>=l; i--)
                {
                    res.push_back(mat[m-1][i]);
                }
                m--;
            }
            
            if(l < n)
            {
                for(int i=m-1; i>=k; i--)
                {
                    res.push_back(mat[i][l]);
                }
                l++;
            }
        }
        
        return res;
    }
};