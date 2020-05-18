class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> fwd(n), bwd(n);
        
        fwd[0] = arr[0];
        int curr_sum = arr[0];
        
        for(int i=1; i<n; i++)
        {
            curr_sum = max(arr[i], curr_sum+arr[i]);
            fwd[i] = curr_sum;
        }
        
        int overall_max = arr[n-1];
        bwd[n-1] = curr_sum = arr[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            curr_sum = max(curr_sum+arr[i], arr[i]);
            bwd[i] = curr_sum;
            overall_max = max(overall_max, curr_sum);
        }
        
        int res = overall_max;
        
        for(int i=1; i<n-1; i++)
        {
            if(arr[i] < 0)
                res = max(fwd[i-1] + bwd[i+1], res);
        }
        
        return res;
    }
};