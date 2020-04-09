class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        
        for(int i=0; i<S.size(); i++)
        {
            if(S[i] == '#')
            {
                if(!s.empty())
                {
                    s.pop();
                }
                else
                {
                    continue;
                }
            }
            
            else 
            {
                s.push(S[i]);
            }
        }
        
        for(int i=0; i<T.size(); i++)
        {
            if(T[i] == '#')
            {
                if(!t.empty())
                {
                    t.pop();
                }
                else
                {
                    continue;
                }
            }
            
            else 
            {
                t.push(T[i]);
            }
        }
        
        if(s.size() != t.size())
            return false;
        
        while(!s.empty())
        {
            if(s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        
        return true;
    }
};