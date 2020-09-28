class Solution {
public:
    bool isRobotBounded(string cmd) {
        int dir = 0;
        int x = 0, y = 0;
        
        for(int i=0; i<cmd.size(); i++)
        {
            char c = cmd[i];
            if(c == 'L')
            {
                if(dir == 0)
                    dir = 3;
                else
                    dir--;
            }
            
            else if(c == 'R')
            {
                if(dir == 3)
                    dir = 0;
                else
                    dir++;
            }
            
            else
            {
                if(dir == 0)
                {
                    y++;
                }
                else if(dir == 1)
                {
                    x++;
                }
                else if(dir == 2)
                {
                    y--;
                }
                else
                {
                    x--;
                }
            }
            
        }
        
        return (x==0 && y==0) || dir > 0;
    }
};