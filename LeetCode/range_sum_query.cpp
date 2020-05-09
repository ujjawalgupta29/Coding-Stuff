class NumArray {
public:
    vector<int> numbers;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        numbers.push_back(0);
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            numbers.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return numbers[j+1] - numbers[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */