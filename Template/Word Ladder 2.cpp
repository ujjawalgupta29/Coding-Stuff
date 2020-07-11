static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 1;
        int min_level = INT_MAX;
        
        unordered_set<string> visited;
        
        while(!q.empty())
        {
                auto path = q.front();
                q.pop();
                
                if(path.size() > level)
                {
                    for(string s : visited)
                    {
                        words.erase(s);
                    }
                    visited.clear();
                    
                    if (path.size() > min_level)
                        break;
                
                    else
                        level = path.size();
                }
                
                
                string last = path.back();
                
                for(int i=0; i<last.size(); i++)
                {
                    string lastWord = last;
                    for(int j=0; j<26; j++)
                    {
                        lastWord[i] = 'a' + j;
                        if(words.find(lastWord) != words.end())
                        {
                            vector<string> newPath = path;
                            newPath.push_back(lastWord);
                            visited.insert(lastWord);
                            
                            if(lastWord == endWord)
                            {
                                res.push_back(newPath);
                                min_level = level;
                            }
                            else
                                q.push(newPath);
                        }
                    }
                }
        }
        return res;
    }
};