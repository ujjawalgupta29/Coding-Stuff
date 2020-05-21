class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        
        for(auto v : indices)
        {
            rows[v[0]]++;
            cols[v[1]]++;
        }
        
        int counts = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int val = rows[i] + cols[j];
                if(val % 2 != 0)
                    counts++;
            }
        }
        
        return counts;
    }
};