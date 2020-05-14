class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int dp[n][n];
        unordered_map<int, int> mp;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            mp[A[i]] = i;
            for(int j=0; j<i; j++)
            {
                int diff = A[i] - A[j];
                int k = (mp.find(diff) != mp.end()) ? mp[diff] : -1;
                dp[j][i] = (diff < A[j] && k != -1) ? dp[k][j] + 1 : 2;
                ans = max(ans, dp[j][i]);
            }
        }
        
        return (ans > 2) ? ans : 0;
    }
};