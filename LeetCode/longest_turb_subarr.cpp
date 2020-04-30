class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size();
        if(n <= 1)
            return n;
        
        int begin1 = 0, begin2 = 0;
        int max_len = 1;
        int end = 0;
        
        for(end=0; end<n-1; end++)
        {
            if( (end % 2 == 0 && a[end] >= a[end+1]) || (end % 2 != 0 && a[end] <= a[end+1]) )
            {
                if(end - begin1 + 1 > max_len)
                    max_len = end - begin1 + 1;
                begin1 = end+1;
            }
            
            if( (end % 2 == 0 && a[end] <= a[end+1]) || (end % 2 != 0 && a[end] >= a[end+1]) )
            {
                if(end - begin2 + 1 > max_len)
                    max_len = end - begin2 + 1;
                begin2 = end+1;
            }
        }
        

        if(end - begin1 + 1 > max_len)
                max_len = end - begin1 + 1;

        if(end - begin2 + 1 > max_len)
                max_len = end - begin2 + 1;   
        
        return max_len;
    }
};