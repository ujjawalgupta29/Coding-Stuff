#include<bits/stdc++.h>
using namespace  std;

void rotate(vector<int> &nums, int start, int end)
{
    int temp = nums[end];
    for(int i=end; i>start; i--)
    {
        nums[i] = nums[i-1];
    }
    nums[start] = temp;
}

void rearrange(vector<int> &nums, int n)
{
    int outOfPlace = -1;
    for(int i=0; i<n; i++)
    {
        if(outOfPlace != -1)
        {
            if(nums[outOfPlace] >= 0 && nums[i] < 0 || nums[outOfPlace] < 0 && nums[i] >= 0)
            {
                rotate(nums, outOfPlace, i);
                if(i - outOfPlace >= 2)
                {
                    outOfPlace += 2;
                }
                else
                {
                    outOfPlace = -1;
                }
            }
        }
        
        if(outOfPlace == -1)
        {
            if(nums[i] >= 0 && i%2 != 0 || nums[i] < 0 && i%2 == 0)
            {
                outOfPlace = i;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        rearrange(nums, n);        
        
        for(int x : nums)
            cout << x << " ";
            
        cout << endl;
    }
}