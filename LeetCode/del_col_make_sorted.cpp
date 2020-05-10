class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int del = 0;
        int sz = A.size();
        if(sz <= 1)
            return 0;
        
        int len = A[0].size();
        
        for(int c = 0; c<len; c++)
        {
            for(int i=1; i<sz; i++)
            {
                if(A[i][c] < A[i-1][c])
                {
                    del++;
                    break;
                }
            }
        }
        
        return del;
        
    }
};