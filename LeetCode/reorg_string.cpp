class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        
        unordered_map<char, int> mp;
        
        for(char ch : s)
        {
            mp[ch]++;
        }
        
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        
        string res;
        pair<int, char> prev = {-1, '#'};
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            char ch = top.second;
            if(ch == '#')
                break;
            
            if(prev.first > 0 || prev.second == '#')
                pq.push(prev);
            
            int freq = top.first;
            
            res += ch;
            freq--;
            
            prev = {freq, ch};
        }
        
        if(res.size() == s.size())
            return res;
        
        return "";
    }
};