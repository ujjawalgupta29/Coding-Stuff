class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        if(len == 0)
            return true;
        
        stack<int> paran;
        stack<int> star;
        
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
                paran.push(i);
            
            else if(s[i] == ')')
            {
                if(paran.empty() && star.empty())
                    return false;
                else if(!paran.empty())
                    paran.pop();
                else if(!star.empty())
                    star.pop();
            }
            
            else
                star.push(i);
        }
        
        while(!paran.empty() && !star.empty())
        {
            if(star.top() < paran.top())
                return false;
            star.pop();
            paran.pop();
        }
        
        return paran.empty();
    }
};