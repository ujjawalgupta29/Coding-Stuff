class Solution {
public:
    
    void flood_fill(vector<vector<int>>& image, int x, int y, int color, int newColor, vector<vector<int>> &visited)
    {
        if(x < 0 || x > image.size() - 1 || y < 0 || y > image[0].size()-1 || image[x][y] != color || visited[x][y])
            return;
        
        visited[x][y] = 1;
        image[x][y] = newColor;
        flood_fill(image, x+1, y, color, newColor, visited);
        flood_fill(image, x, y+1, color, newColor, visited);
        flood_fill(image, x-1, y, color, newColor, visited);
        flood_fill(image, x, y-1, color, newColor, visited);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        if(m == 0)
            return image;
        
        int n = image[0].size();
        if(n == 0)
            return image;
        int color = image[sr][sc];
        
        if(color == newColor)
            return image;
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        flood_fill(image, sr, sc, color, newColor, visited);
        return image;
    }
};