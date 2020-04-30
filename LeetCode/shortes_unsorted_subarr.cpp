class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_arr(n);
        vector<int> max_arr(n);
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > max_ele)
                max_ele = nums[i];
            max_arr[i] = max_ele;
        }
        
        for(int i=n-1; i >= 0; i--)
        {
            if(nums[i] < min_ele)
                min_ele = nums[i];
            min_arr[i] = min_ele;
        }
        int i=0, j=n-1;
        
        while(i<n && nums[i] <= min_arr[i]) i++;
        while(j > i && nums[j] >= max_arr[j]) j--;
        
        return j - i + 1;
    }
};