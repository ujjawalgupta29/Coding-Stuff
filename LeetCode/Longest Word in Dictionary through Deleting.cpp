static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string s1, string s2){
            if(s1.size() != s2.size())
                return s1.size() > s2.size();
            return s1 < s2;
        });
        
        for(string str : d)
        {
            if(check(str, s))
                return str;
        }
        
        return "";
    }
    
    bool check(string word, string s)
    {
        if(word.size() > s.size())
            return false;
        
        int idx1=0;
        int n = word.size();
        
        for(char c : s)
        {
            if(word[idx1] == c)
            {
                idx1++;
            }
            
            if(idx1 == n)
                return true;
        }
        
        return false;
    }
};