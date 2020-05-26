class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        
        vector<vector<int>> people(40);
        
        for(int i=0; i<n; i++)
        {
            for(int h : hats[i])
            {
                people[h-1].push_back(i);
            }
        }
        
        vector<int> masks(1<<n);
        masks[0] = 1;
        
        for(int i=0; i<40; i++)
        {
            for(int j = (1<<n) - 1; j>=0; j--)
            {
                for(int p : people[i])
                {
                    if( (1<<p & j) == 0)
                    {
                        masks[j | (1<<p)] += masks[j];
                        masks[j | (1<<p)] %= mod;
                    }
                }
            }
        }
        
        return masks[ (1 << n) - 1];
    }
};