class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> mp;
        for(char c : J)
            mp[c]++;
        
        int counts = 0;
        for(char c : S)
        {
            if(mp.find(c) != mp.end())
                counts++;
        }
        return counts;
    }
};