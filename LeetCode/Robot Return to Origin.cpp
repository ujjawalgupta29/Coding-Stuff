class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        
        for(char ch : moves)
        {
            if(ch == 'L')
            {
                y--;
            }
            
            else if(ch == 'R')
            {
                y++;
            }
            
            else if(ch == 'U')
            {
                x--;
            }
            
            else if(ch == 'D')
            {
                x++;
            }
        }
        
        return (x == 0 && y == 0);
    }
};