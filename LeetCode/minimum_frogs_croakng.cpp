class Solution {
public:
    int minNumberOfFrogs(string frog) {
        vector<int> c;
        vector<int> r;
        vector<int> o;
        vector<int> a;
        vector<int> k;
        vector<int> indices(100002, 0);
        
        for(int i=0; i<frog.size(); i++)
        {
            if(frog[i] == 'c')
            {
                c.push_back(i);
                indices[i] = 1;
            }
            
            else if(frog[i] == 'r')
            {
                r.push_back(i);
            }
            
            else if(frog[i] == 'o')
            {
                o.push_back(i);
            }
            
            else if(frog[i] == 'a')
            {
                a.push_back(i);
            }
            
            else
            {
                k.push_back(i);
            }
        }
        
        int len = c.size();
        
        if(r.size() != len || o.size() != len || a.size() != len || k.size() != len)
            return -1;
        
        for(int i=1; i<indices.size(); i++)
        {
            indices[i] += indices[i-1];
        }
        
        
        int idx1=0;
        int end;
        int counts = 0;
        
        while(idx1 < len)
        {
            if(c[idx1] < r[idx1] && r[idx1] < o[idx1] && o[idx1] < a[idx1] && a[idx1] < k[idx1])
            {
                end = k[idx1];
                int temp_counts = 1 + indices[k[idx1]] - indices[c[idx1]];
                counts = max(counts, temp_counts);
            }
            
            else
            {
                return -1;
            }
            
            idx1++;
        }
        
        return counts;
    }
};