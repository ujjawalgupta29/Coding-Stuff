class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        
        for(int x=A.size(); x > 0 ; x--)
        {
            int i=0;
            while(A[i] != x)
                i++;
            
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i+1);
            
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        
        return res;
    }
};