class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int first = 0;
        int second = 0;
        
        vector<int> res;
        
        while(first < nums1.size() && second < nums2.size())
        {
            if(nums1[first] == nums2[second])
            {
                if(res.size() == 0 || res[res.size() - 1] != nums1[first]) 
                    res.push_back(nums1[first]);
                first++;
                second++;
            }
            
            else if(nums1[first] < nums2[second])
                first++;
            
            else
                second++;
        }
        
        return res;
    }
};