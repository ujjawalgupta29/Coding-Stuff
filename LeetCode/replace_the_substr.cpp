class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> mp;
        
        for(char ch : s)
            mp[ch]++;
        
        int n = s.size();
        int k = n/4;
        int min_len = INT_MAX;
        int start = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]--;
            
            while(start < n && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k)
            {
                min_len = min(min_len, i-start+1);
                mp[s[start]]++;
                start++;
            }
        }
        
        return min_len;
    }
};