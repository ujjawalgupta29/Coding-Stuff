static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    unordered_map<string, vector<string>> mp;
    
    vector<string> combine(string word, vector<string> prev)
    {
        for(int i=0; i<prev.size(); i++)
        {
            prev[i] += " " + word;
        }
        
        return prev;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordsSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, wordsSet);
    }
    
    vector<string> wordBreakHelper(string s, unordered_set<string> wordsSet)
    {
        if(mp.count(s))
            return mp[s];
        
        vector<string> result;
        if(wordsSet.count(s))
            result.push_back(s);
        
        for(int i=1; i < s.size(); i++)
        {
            string word = s.substr(i);
            if(wordsSet.count(word))
            {
                string rem = s.substr(0,i);
                vector<string> prev = combine(word, wordBreakHelper(rem, wordsSet));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        
        mp[s] = result;
        return result;
    }
};