static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        int len = 1;
        int res = 0;
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
                
                if(i >= len && j >= len && 
                   sum[i][j] - sum[i-len][j] - sum[i][j-len] 
                   + sum[i-len][j-len] <= threshold)
                {
                    res = len;
                    len++;
                }
            }
        }
        
        return res;
    }
};