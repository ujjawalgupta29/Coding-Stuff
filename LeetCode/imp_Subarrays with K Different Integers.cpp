class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k-1);
    }

    int atMost(vector<int> &A, int k)
    {
        int res=0, start=0;
        unordered_map<int, int> mp;
        
        for(int j=0; j<A.size(); j++)
        {
            if(!mp[A[j]]++)
            {
                k--;
            }
            
            while(k < 0)
            {
                if (!--mp[A[start]])
                    k++;
                start++;
            }
            
            res += j - start + 1;
        }
        
        return res;
    }
};