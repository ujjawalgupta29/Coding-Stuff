class Solution {
public:
    vector<int> twoSum(vector<int>& num, int x) {
        int l = 0;
        int r = num.size()-1;
        
        while(l < r)
        {
            int sum = num[l] + num[r];
            if(sum == x)
                break;
            
            else if(sum < x)
                l++;
            
            else
                r--;
        }
        
        return vector<int>{l+1, r+1};
    }
};