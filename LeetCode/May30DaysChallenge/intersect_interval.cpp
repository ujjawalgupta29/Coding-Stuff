class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = A.size();
        int b = B.size();
        vector<vector<int>> res;
        
        int idx1 = 0, idx2 = 0;
        
        while(idx1 < a && idx2 < b)
        {
            
            if(A[idx1][1] < B[idx2][0])
            {
                idx1++;
            }
            
            else if(A[idx1][0] > B[idx2][1])
            {
                idx2++;
            }
            
            else
            {
                if(A[idx1][0] <= B[idx2][0] && A[idx1][1] >= B[idx2][1])
                {
                    res.push_back({B[idx2][0], B[idx2][1]});
                }
                
                else if(A[idx1][0] >= B[idx2][0] && A[idx1][1] <= B[idx2][1])
                {
                    res.push_back({A[idx1][0], A[idx1][1]});
                }
                
                else if(A[idx1][0] <= B[idx2][0] && A[idx1][1] >= B[idx2][0])
                {
                    res.push_back({B[idx2][0], A[idx1][1]});
                }
                
                else if(A[idx1][0] >= B[idx2][0] && A[idx1][0] <= B[idx2][1])
                {
                    res.push_back({A[idx1][0], B[idx2][1]});
                }
                
                if(A[idx1][1] == B[idx2][1])
                {
                    idx1++;
                    idx2++;
                }
                
                else if(A[idx1][1] > B[idx2][1])
                {
                    idx2++;
                }
                
                else
                {
                    idx1++;
                }
            }
        }
        
        return res;
    }
};