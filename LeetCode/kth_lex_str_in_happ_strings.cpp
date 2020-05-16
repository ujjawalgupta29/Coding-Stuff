class Solution {
public:
    
    vector<string> res;
    
    void generate(vector<char> str, int n, int k, string temp)
    {
        if(res.size() == k)
            return;
        
        if(n == temp.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0; i<=2; i++)
        {
            if(temp.size() == 0 || temp[temp.size()-1] != str[i])
            {
                temp += str[i];
                generate(str, n, k, temp);
                temp.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        vector<char> str{'a', 'b', 'c'};
        generate(str, n, k, "");
        return (res.size() == k) ? res[k-1] : "";
    }
};