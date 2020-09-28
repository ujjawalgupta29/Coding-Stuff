#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> res;

    for(int i=0; i<n; i++)
        cin >> nums[i];

    int l=0, r=n-1;

    while(l <= r)
    {
        if(nums[l] == nums[r])
        {
            res.push_back(nums[l]);
            l++;
            r--;
        }

        else if(nums[l] < nums[r])
        {
            int temp = nums[l] + nums[r];
            int sum = 0;
            while(sum < nums[r] && l < r)
            {
                sum += nums[l];
                l++;
            }
            if(sum == nums[r])
                res.push_back(nums[r]);
            else
            {
                res.push_back(temp);
            }
            
            r--;
        }

        else
        {
            int temp = nums[l] + nums[r];
            int sum = 0;
            while(sum < nums[l] && l < r)
            {
                sum += nums[r];
                r--;
            }
            
            if(sum == nums[l])
                res.push_back(nums[l]);
            else
            {
                res.push_back(temp);
            }
            l++;
        }
        
    }

    for(int x : res)
        cout << x << " ";
    for(int i=res.size()-2; i>=0; i--)
        cout << res[i] << " ";

    cout << endl;
}