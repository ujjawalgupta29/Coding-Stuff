class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int pos=0, neg;
        while(pos < A.size() && A[pos] < 0)
            pos++;
        
        neg = pos - 1;
        
        vector<int> res;
        
        while(neg >= 0 && pos < A.size())
        {
            if( abs(A[neg]) > A[pos])
            {
                res.push_back(A[pos]*A[pos]);
                pos++;
            }
            else
            {
                res.push_back(A[neg]*A[neg]);
                neg--;
            }
        }
        
        while(neg >= 0)
        {
            res.push_back(A[neg]*A[neg]);
            neg--;
        }
        
        while(pos < A.size())
        {
            res.push_back(A[pos]*A[pos]);
            pos++;
        }
        
        return res;
    }
};                                                                              