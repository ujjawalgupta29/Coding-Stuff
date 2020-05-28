class Solution {
public:
    
    bool check(int x, int y, int x_c, int y_c, int r)
    {   
        return ( (x_c - x)*(x_c - x) + (y_c - y)*(y_c - y) - r*r ) <= 0;
    }
    
    bool checkOverlap(int r, int x_c, int y_c, int x1, int y1, int x2, int y2) {
        
        if(x_c >= x1 && x_c <= x2 && y_c >= y1 && y_c <= y2)
            return 1;
        
        for(int i=x1; i<=x2; i++)
        {
            if(check(i, y1, x_c, y_c, r) || check(i, y2, x_c, y_c, r))
                return 1;
        }
        
        for(int i=y1; i<=y2; i++)
        {
            if(check(x1, i, x_c, y_c, r) || check(x2, i, x_c, y_c, r))
                return 1;
        }
        
        return 0;
    }
};