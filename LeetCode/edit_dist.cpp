class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> op(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<m+1; i++)
        {
            op[i][0] = i;
        }
        
        for(int i=0; i<n+1; i++)
        {
            op[0][i] = i;
        }
        
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                    op[i][j] = op[i-1][j-1];
                else
                {
                    op[i][j] = 1 + min(op[i-1][j-1], min(op[i-1][j], op[i][j-1]));
                }
            }
        }
        
        return op[m][n];
    }
};