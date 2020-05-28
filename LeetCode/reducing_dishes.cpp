class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        
        int max_s = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                int counter = 1;
                int temp_s = 0;
                for(int k=j; k<=i; k++)
                {
                    temp_s += (counter++) * s[k];
                }
                max_s = max(max_s, temp_s);
            }
        }
        
        return max_s;
    }
};