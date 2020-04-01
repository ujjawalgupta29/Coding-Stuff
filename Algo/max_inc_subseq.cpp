#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    vector<int> dp(n);
    vector<int> sequence(n, -1);
    dp = nums;
    int max_value = INT_MIN;
    int max_idx;

    for(int i=1; i<n; i++) {
        int idx = -1;
        for(int j = 0; j<i; j++) {
            if(nums[i] > nums[j] && dp[i] < nums[i] + dp[j])
            {
                dp[i] = nums[i] + dp[j];
                idx = j;
            }
        }
        if(dp[i] > max_value) {
            max_value = dp[i];
            max_idx = i;
        }
        sequence[i] = idx;
    }

    cout<<"Max Sum:- "<<dp[max_idx]<<endl;
    vector<int> result;
    int index = max_idx;
    result.push_back(nums[index]);
    while(sequence[index] != -1)
    {
        result.push_back(nums[sequence[index]]);
        index = sequence[index];
    }
    
    for(int x : result)
        cout<<x<<" ";
    cout<<endl;
}