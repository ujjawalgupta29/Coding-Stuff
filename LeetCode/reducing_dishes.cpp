class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        
        int res= 0;
        int sum_till_now = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] + sum_till_now <= 0)
            {
                break;
            }
                
            sum_till_now += s[i];
            res += sum_till_now;
        }
        
        return res;
    }
};