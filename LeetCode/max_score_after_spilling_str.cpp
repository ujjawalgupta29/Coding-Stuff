class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        vector<int> zero_left;
        vector<int> ones_right(len);
        
        int count_0 = 0;
        for(char c : s)
        {
            if(c == '0')
                count_0 ++;
            zero_left.push_back(count_0);
        }
        
        int count_1 = 0;
        for(int i=len-1; i>=0; i--)
        {
            if(s[i] == '1')
                count_1 ++;
            ones_right[i] = count_1;
        }
        
        int i=0, j=1;
        int max_sum = 0;
        
        while(i < len-1)
        {
            int temp = zero_left[i] +ones_right[j];
            if(temp > max_sum)
                max_sum = max(max_sum, temp);
            i++;
            j++;
        }
        
        return max_sum;
    }
};