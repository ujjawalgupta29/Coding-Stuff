class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(auto x : nums)
            mp[x]++;
        
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        
        for (auto it = mp.begin(); it != mp.end(); ++it) 
        { 
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > mp.size() - k)
            {
                result.push_back(pq.top().second);
                pq.pop();
            }
        } 

        return result;

    }
};