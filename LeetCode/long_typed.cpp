class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        
        if(n < m)
            return 0;
        
        if(n == m)
            return name==typed;
        
        int idx1=0, idx2=0;
        
        while(idx1 < m && idx2 < n)
        {
            if(name[idx1] == typed[idx2])
                idx1++, idx2++;
            
            else if(idx2 > 0 && typed[idx2] == typed[idx2-1])
                idx2++;
            
            else
                return 0;
        }
        
        while(idx2 != n)
        {
            if(typed[idx2] != typed[idx2-1] )
                return 0;
            idx2++;
        }
        
        return idx1 == m;
    }
};