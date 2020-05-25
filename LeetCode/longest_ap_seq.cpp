class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n == 2)
            return 2;
        
        int max_pairs = 0;
        
        unordered_map<int, unordered_map<int, int>> mp;
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff = A[i] - A[j];
                
                mp[i][diff] = (mp[j].count(diff)) ? mp[j][diff] + 1 : 2;
 
                max_pairs = max(max_pairs, mp[i][diff]);
            }
        }
        
        return max_pairs;
    }
};