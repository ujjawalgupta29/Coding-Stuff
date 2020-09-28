class Solution {
public:
    
    int kadane(vector<int> &temp, int target)
    {
        unordered_map<int, int> mp;
        int subarr = 0;
        
        int curr_sum = 0;
        
        for(int x : temp)
        {
            curr_sum += x;
            
            if(curr_sum == target)
                subarr++;
            
            if(mp.find(curr_sum - target) != mp.end())
                subarr += mp[curr_sum - target];
            
            mp[curr_sum]++;
        }
        
        return subarr;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int l=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        while(l < n)
        {
            vector<int> temp(m, 0);
            
            for(int r=l; r<n; r++)
            {
                for(int i=0; i<m; i++)
                    temp[i] += matrix[i][r];
                
                res += kadane(temp, target);
            }
            
            l++;
        }
        
        return res;
    }
};