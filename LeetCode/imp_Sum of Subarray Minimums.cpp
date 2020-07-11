static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        long sum = 0;
        
        stack<pair<int, int>> s1, s2;
        vector<int> left(n), right(n);
        
        for(int i=0; i<n; i++)
        {
            int count = 1;
            while(!s1.empty() && s1.top().first > A[i])
            {
                count += s1.top().second;
                s1.pop();
            }
            
            s1.push({A[i], count});
            left[i] = count;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            int count = 1;
            while(!s2.empty() && s2.top().first >= A[i])
            {
                count += s2.top().second;
                s2.pop();
            }
            
            s2.push({A[i], count});
            right[i] = count;
        }
        
        for(int i=0; i<n; i++)
        {
            sum = (sum + A[i]*left[i]*right[i]) % mod;
        }
        
        return sum;
    }
};