class Solution {
public:
    int dp[501][501];
    
    int score(vector<int>& piles, int l, int r)
    {
        if(r - l == 1)
            return max(piles[l], piles[r]);
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int ifleft = piles[l] + max( score(piles, l+2, r), score(piles, l+1, r-1) );
        int ifright = piles[r] + max( score(piles, l+1, r-1), score(piles, l, r-2) );
        dp[l][r] = max(ifleft, ifright);
        
        return dp[l][r];
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int a_score = score(piles, 0, piles.size() - 1);
        int sum = 0;
        for(int i=0; i<piles.size(); i++)
            sum += piles[i];
        
        return a_score > (sum - a_score);
    }
};