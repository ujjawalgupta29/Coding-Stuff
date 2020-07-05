class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = 0;
        
        while(x || y)
        {
            int bit1 = x & 1;
            int bit2 = y & 1;
            
            if(bit1 != bit2)
                dis++;
            
            x = x >> 1;
            y = y >> 1;
        }
        
        return dis;
    }
};