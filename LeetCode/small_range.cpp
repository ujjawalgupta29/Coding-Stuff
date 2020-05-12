class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mini=INT_MAX, maxi=INT_MIN;
        for(int x : A)
        {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        
        return max(0, maxi - mini - 2*K);
    }
};