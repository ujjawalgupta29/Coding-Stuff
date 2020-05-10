class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> squares(m, vector<int>(n, 0));
        int counts = 0;
        
        for(int i=0; i<n; i++)
        {
            squares[0][i] = matrix[0][i];
            counts += matrix[0][i];
        }
        for(int i=1; i<m; i++)
        {
            squares[i][0] = matrix[i][0];
            counts += matrix[i][0];
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j])
                    squares[i][j] = min(squares[i-1][j-1], min(squares[i-1][j], 
                                                          squares[i][j-1])) + 1;
                counts += squares[i][j];
            }
        }

        
        return counts;
    }
};
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();