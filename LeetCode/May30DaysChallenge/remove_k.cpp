class Solution {
public:
    
    void insert(deque<char> &dq, char c)
    {
        if(dq.empty())
            dq.push_back(c);
        else
        {
            char temp = dq.back();
            while(temp > c && !dq.empty())
            {
                dq.pop_back();
                if(!dq.empty())
                    temp = dq.back();
            }
            dq.push_back(c);
        }
    }
    
    string build(string num, int k)
    {
        deque<char> dq;
        int len = num.size();
        
        int i;
        for(i=0; i<=k; i++)
        {
            insert(dq, num[i]);
        }
        
        string res = "";
        while(i < len)
        {
            res += dq.front();
            dq.pop_front();
            
            insert(dq, num[i]);
            i++;
        }
        res += dq.front();
        dq.pop_front();
        return res;
    }
    
    string removeKdigits(string num, int k) {
        
        if(k >= num.size())
            return "0";
        
        string res = build(num, k);
        
        int i=0;
        while(i < res.size() && res[i] == '0')
            i++;
        
        return (i < res.size()) ? res.substr(i) : "0";
    }
};