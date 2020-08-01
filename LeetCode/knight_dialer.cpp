static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int knightDialer(int N) {
        vector<vector<int>> paths = {
            {4,6}, {6,8}, {7,9}, {4,8},
            {3,9,0}, {}, {1,7,0},
            {6,2}, {1,3}, {2,4},
        };
        vector<vector<int>> dp(N+1, vector<int>(10, 0));
        
        for(int i=0; i<10; i++)
            dp[1][i] = 1;
        
        for(int i=2; i<=N; i++)
        {
            for(int j=0; j<10; j++)
            {
                for(int x : paths[j])
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][x]) % mod;
                }
            }
        }
        
        long res = 0;
        for(int i=0; i<10; i++)
        {
            res = (res + dp[N][i]) % mod;
        }
        
        return res;
    }
};