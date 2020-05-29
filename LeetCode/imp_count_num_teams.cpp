class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int counts = 0;
        int smaller_left, larger_right, smaller_right, larger_left;
        
        for(int i=0; i<n; i++)
        {
            smaller_left = 0;
            larger_left = 0;
            for(int j=0; j<i; j++)
            {
                if(rating[j] < rating[i])
                    smaller_left++;
                else
                    larger_left++;
            }
            
            smaller_right=0;
            larger_right = 0;
            for(int j=i+1; j<n; j++)
            {
                if(rating[j] > rating[i])
                    larger_right++;
                else
                    smaller_right++;
            }
            
            counts += larger_left*smaller_right + larger_right*smaller_left;
        }
        
        return counts;
    }
};