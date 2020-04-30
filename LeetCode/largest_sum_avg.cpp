class Solution {
public:
    double memo[101][101];
    double largestSumOfAverages(vector<int>& A, int K) {
        
        int n = A.size();
        memset(memo, 0, sizeof(memo));
        double sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            memo[i+1][1] = sum/(i+1);
        }
        
        return groups(A, n, K);
    }
    
    double groups(vector<int> A, int n, int k)
    {
        if(memo[n][k] > 0)
            return memo[n][k];
        
        if(n < k)
            return 0;
        
        double sum = 0;
        for(int i=n-1; i>0; i--)
        {
            sum += A[i];
            memo[n][k] = max(memo[n][k], groups(A, i, k-1) + sum / (n - i));
        }
        
        return memo[n][k];
    }
};