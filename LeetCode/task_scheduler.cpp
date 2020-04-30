class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        unordered_map<char, int> mp;
        int max_freq = -1;
        
        for(char c : tasks)
        {
            mp[c]++;
            max_freq = max(max_freq, mp[c]);
        }
        
        int counts = 0;
        counts = (max_freq-1) * (n + 1);
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == max_freq)
                counts++;
        }
        
        return max(counts, (int)tasks.size());
    }
};