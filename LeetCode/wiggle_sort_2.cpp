class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        sorted = nums;
        
        sort(sorted.begin(), sorted.end());
        
        int j = 0;
        int k = (n - 1)/2 + 1;
        for(int i = n-1; i>=0; i--)
        {
            nums[i] = sorted[i&1 ? k++ : j++];
        }
    }
};