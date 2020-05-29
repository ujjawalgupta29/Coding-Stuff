class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x : arr)
            mp[x]++;
        
        int max_ans = -1;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->first == it->second)
                max_ans = max(max_ans, it->first);
        }
        
        return max_ans;
    }
};