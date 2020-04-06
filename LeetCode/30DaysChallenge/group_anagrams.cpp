class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map <string, vector<string>> ump;
        
        for(int i=0; i< strs.size(); i++)
        {
            string temp = strs[i];
            // cout<<"check"<<endl;
            temp = c_sort(temp);
            // cout<<temp<<endl;
            ump[temp].push_back(strs[i]);
        }
        
        for(auto i : ump)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
    
    string c_sort(string temp)
    {
        int counts[26];
        memset(counts,0,sizeof(counts));
        for(int i=0; i<temp.length(); i++)
        {
            counts[temp[i] - 'a']++;
        }
        
        string res;
        for(int i=0; i<26; i++)
        {
            res += string(counts[i], i + 'a');
        }
        
        return res;
    }
};