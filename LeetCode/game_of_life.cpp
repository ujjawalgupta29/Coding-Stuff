class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        if(board.size() == 0)
            return;
        if(board[0].size() == 0)
            return;
        
        int m = board.size();
        int n = board[0].size();

        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                int counts = -board[i][j];
                
                for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                    for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                        counts += board[I][J] & 1;
                    
                
                if(board[i][j])   
                {
                    if(counts < 2 || counts > 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 1;
                }
                else
                {
                    if(counts == 3)
                        board[i][j] = 2;
                    else
                        board[i][j] = 0;
                }
            }
            
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == 3)
                    board[i][j] = 0;
                    
            }
        }
    }
};