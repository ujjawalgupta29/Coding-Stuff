class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> gifts(n, 0);
        int rounds = 0;
        
        while(candies > 0)
        {
            for(int i=0; i<n; i++)
            {
                if(candies >= i + 1 + rounds)
                {
                    gifts[i] += i + 1 + rounds;
                    candies -= i + 1 + rounds;
                }
                else
                {
                    gifts[i] += candies;
                    candies = 0;
                    break;
                }
            }
            
            rounds += n;
        }
        
        return gifts;
    }
};