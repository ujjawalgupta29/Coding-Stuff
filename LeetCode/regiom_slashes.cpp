class Solution {
public:
    
    void dfs(vector<vector<int>> &pixels, int i, int j)
    {
        if(i >= pixels.size() || j >= pixels.size() || i < 0 || j < 0 || pixels[i][j] == 1)
            return;
        pixels[i][j] = 1;
        dfs(pixels, i+1, j);
        dfs(pixels, i-1, j);
        dfs(pixels, i, j+1);
        dfs(pixels, i, j-1);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> pixels(grid.size() * 3, vector<int> (grid.size() * 3, 0));
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid.size(); j++)
            {
                if(grid[i][j] == '/')
                {
                    pixels[i*3][j*3 + 2] = 1;
                    pixels[i*3 + 1][j*3 + 1] = 1;
                    pixels[i*3 + 2][j*3] = 1;
                }
                if(grid[i][j] == '\\')
                {
                    pixels[i*3][j*3] = 1;
                    pixels[i*3 + 1][j*3 + 1] = 1;
                    pixels[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        // cout<< " aya" << endl;
        
        int regions = 0;
        
        for(int i=0; i<pixels.size(); i++)
        {
            for(int j=0; j<pixels.size(); j++)
            {
                if(pixels[i][j] == 0)
                {
                    dfs(pixels, i, j);
                    regions++;
                }
            }
        }
        
        return regions;
    }
};