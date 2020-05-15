class Solution {
public:
    
    int kadane(vector<int> A)
    {
        int max_so_far = INT_MIN, curr_sum=0;
        for(int i=0; i<A.size(); i++)
        {
            curr_sum += A[i];
            max_so_far = max(max_so_far, curr_sum);
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return max_so_far;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        
        int case1 = kadane(A);
        
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            A[i] = -A[i];
        }
        
        int case2 = sum + kadane(A);
        
        return (case2 != 0) ? max(case1, case2) : case1;
    }
};