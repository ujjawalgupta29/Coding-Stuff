#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int kadane(vector<int> &temp)
{
    int sum = 0;
    int max_sum = INT_MIN;
    
    for(int i=0; i<temp.size(); i++)
    {
        sum += temp[i];
        
        max_sum = max(max_sum, sum);
        
        if(sum < 0)
            sum = 0;
    }
    
    return max_sum;
}

int solve(vector<vector<int>> nums, int m, int n)
{
    int l, r;
    int max_sum = INT_MIN;
    
    for(l=0; l<n; l++)
    {
        vector<int> temp(m, 0);
        for(r=l; r<n; r++)
        {
            for(int i=0; i<m; i++)
                temp[i] += nums[i][r];
                
            // if(l == 1 && r == 3)
            // {
            //     cout << "temp:-  ";
            //     for(int x : temp)
            //         cout << x << " ";
            // }
            // cout << endl << endl;
            
            int temp_sum = kadane(temp);
            max_sum = max(max_sum, temp_sum);
        }
    }
    
    return max_sum;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        
        vector<vector<int>> nums(m, vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                cin >> nums[i][j];
        }
        
        cout << solve(nums, m, n) << endl;
    }
}