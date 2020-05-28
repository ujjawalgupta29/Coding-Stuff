class Solution {
public:
    
    string mostCommonWord(string para, vector<string>& banned) {
        
        unordered_set<string> ban(banned.begin(), banned.end());
        
        
        for(int i=0; i<para.size(); i++)
        {
            if(!isalpha(para[i]))
                para[i] = ' ';
            
            else
                para[i] = tolower(para[i]);
        }
        
        stringstream ss(para);
        string word;
        unordered_map<string, int> mp;
        int max_freq = 0;
        string res;
        
        while(ss >> word)
        {
            if(ban.find(word) == ban.end())
            {
                mp[word]++;
                if(mp[word] > max_freq)
                {
                    max_freq = mp[word];
                    res = word;
                }
            }
        }
        
        return res;
    }
};