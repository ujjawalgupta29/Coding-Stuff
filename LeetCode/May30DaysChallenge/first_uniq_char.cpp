static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        int counts[26] = {0};
        
        for(int i=0; i<s.length(); i++)
            counts[ s[i] - 'a']++;
        
        for(int i=0; i<s.length(); i++)
            if(counts[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};