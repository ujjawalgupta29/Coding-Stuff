class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0)
        {
            return vector<int>{1};
        }
        
        vector<int> prev = {1, 1};
        
        if(n == 1)
            return prev;
        
        for(int i=2; i<=n; i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int i=1; i<prev.size(); i++)
            {
                curr.push_back(prev[i] + prev[i-1]);
            }
            curr.push_back(1);
            prev = curr;
        }
        
        return prev;
    }
};