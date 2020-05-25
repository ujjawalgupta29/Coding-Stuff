static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxVowels(string s, int k) {
        int sz = s.size();
        int idx=0;
        int max_len = 0;
        int len = 0;
        
        for(int i=0; i<sz; i++)
        {
            
            if(i-idx+1 > k)
            {
                max_len = max(max_len, len);
                if(len == k)
                {
                    break;                    
                }
                if(s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u')
                    len -= 1;
                idx++;
            }
            
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                len++;
            }
            
        }
        //last window check
        max_len = max(max_len, len);
        
        return max_len;
    }
};