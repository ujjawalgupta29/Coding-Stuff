static const auto ____ = [] () {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return nullptr;
}();
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1)
            return 1;
        
        sort(pairs.begin(), pairs.end(), [](const vector<int> v1, 
                                            const vector<int> v2){return v1[1] < v2[1];});
        
        int max_len = 1;
        int idx = 0;
        for(int i=1; i<n; i++)
        {
            if(pairs[i][0] > pairs[idx][1])
            {
                max_len++;
                idx = i;
            }
        }
        
        return max_len;
    }
};