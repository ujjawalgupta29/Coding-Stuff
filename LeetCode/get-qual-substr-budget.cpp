class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int len = s.size();
        vector<int> cost_i(len, 0);
        
        for(int i = 0; i < len; i++)
        {
            cost_i[i] = abs(s[i] - t[i]);;;
        }
        
        // for(int x : cost_i)
        //     cout << x << " ";
        
        int max_len = 0;
        int start = 0;
        int curr_cost = 0;
        
        for(int i=0; i<len; i++)
        {
            curr_cost += cost_i[i];
            if(curr_cost > maxCost)
            {
                curr_cost -= cost_i[start];
                start++;
            }
            else
            {
                 if(i - start + 1 > max_len)
                    max_len = i - start + 1;
            }
        }
        
        return max_len;
    }
};