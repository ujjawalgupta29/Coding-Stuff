class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.begin(), cit.end());
        int n = cit.size();

        int max_h = 0;
        
        for(int i=0; i<n; i++)
        {
            if(n - i >= cit[i])
                max_h = cit[i];

            else
                max_h = max(max_h, n-i);
        }
        
        return max_h;
    }
};