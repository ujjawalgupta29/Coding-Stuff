class Solution {
public:
    
    string add_one(string s)
    {
        int last = s.size()-1;
        s[last] = '0';
        
        int i = last-1;
        
        while(i>=0 && s[i] == '1')
        {
            s[i] = '0';
            i--;
        }
        
        if(i < 0)
        {
            s = "1" + s;
        }
        
        else
        {
            s[i] = '1';
        }
        
        return s;
    }
    
    int numSteps(string s) {
        int counts = 0;
        while(s != "1")
        {
            int sz = s.size();
            int last = sz - 1;
            counts++;
            
            if(s[last] == '0')
                s.pop_back();
            
            else
            {
                s = add_one(s);
            }
            
        }
        
        return counts;
    }
};