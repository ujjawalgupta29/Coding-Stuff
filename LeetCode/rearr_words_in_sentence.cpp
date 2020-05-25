static bool cmp(pair<string,int>&a,pair<string,int>&b)
{
    if(a.first.size()==b.first.size())
    {
        return a.second<b.second;
    }
    return a.first.size()<b.first.size();
}

class Solution {
public:
    string arrangeWords(string text) {
        
        text[0] = text[0] + 32;
        
        stringstream ss(text);
        string word;
        vector<pair<string, int>> str;
        int i=0;
        
        while(ss >> word)
        {
            str.push_back({word, i});
            i++;
        }
            
        sort(str.begin(), str.end(), cmp);
        
        string res;
        for(int i=0; i<str.size(); i++)
        {
            res += str[i].first;
            if(i != str.size()-1)
                res += " ";
        }
        
        res[0] = res[0] - 32;
        
        return res;
    }
};