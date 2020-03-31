#include<bits/stdc++.h>
using namespace std;

bool correct_order(int i, vector<int> &nums)
{
    if(i == 0)
        return nums[i] < nums[i+1];

    if(i == nums.size()-1)
        return nums[i] > nums[i-1];

    return (nums[i] > nums[i-1]) && (nums[i] < nums[i+1]);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> result(2);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    int min_unsorted = INT_MAX;
    int max_unsorted = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(! correct_order(i, nums))
        {
            min_unsorted = min(min_unsorted, nums[i]);
            max_unsorted = max(max_unsorted, nums[i]);
        }
    }

    if(min_unsorted == INT_MAX)
        result [0] = result[1] = -1;

    int left =0 ;
    while(nums[left] <= min_unsorted) left++;

    int right = n-1;
    while(nums[right] >= max_unsorted) right--;

    result[0] = left;
    result[1] = right;

    cout<<result[0]<<" "<<result[1]<<endl;

}