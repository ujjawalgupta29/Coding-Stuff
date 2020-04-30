class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int max_cust = 0;
        
        int n = grumpy.size();
        for(int i=0; i<n; i++)
        {
            if(!grumpy[i])
                max_cust += customers[i];
        }
        
        int max_grump = 0;
        int begin = 0;
        int end = 0;
        int temp_sum = 0;
        
        while(end < n)
        {
            if(grumpy[end])
                temp_sum += customers[end];
            
            if(end - begin + 1 == X)
            {
                if(temp_sum > max_grump)
                    max_grump = temp_sum;
                temp_sum -= (grumpy[begin] == 1) ? customers[begin] : 0;
                begin++;
            }
            
            end++;
        }
        
        return max_cust + max_grump;
    }
};