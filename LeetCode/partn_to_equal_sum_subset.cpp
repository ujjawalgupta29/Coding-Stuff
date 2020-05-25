class Solution {
    public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0, maxNum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum % k != 0 || maxNum > sum / k) {
            return false;
        }
        vector<int> visited(nums.size(), 0);
        return canPartitionKSubsetsFrom(nums, k, visited, sum / k, 0, 0);
    }
    
    bool canPartitionKSubsetsFrom(vector<int> nums, 
                                             int k,
                                             vector<int> visited, 
                                             int targetSubsetSum, 
                                             int curSubsetSum, 
                                             int nextIndexToCheck) {
        if (k == 0) {
            return true;
        }
        
        if (curSubsetSum == targetSubsetSum) {
            return canPartitionKSubsetsFrom(nums, 
                                            k - 1,
                                            visited,
                                            targetSubsetSum,
                                            0,
                                            0);
        }
        
        for (int i = nextIndexToCheck; i < nums.size(); i++) {
            if (!visited[i] && curSubsetSum + nums[i] <= targetSubsetSum) {
                visited[i] = true;
                if (canPartitionKSubsetsFrom(nums, 
                                             k,
                                             visited,
                                             targetSubsetSum,
                                             curSubsetSum + nums[i],
                                             i + 1)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
};