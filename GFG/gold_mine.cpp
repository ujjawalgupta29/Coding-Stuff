#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        
        int max_gold = INT_MIN;
        for(int i=0; i<m; i++)
            max_gold = max(max_gold, nums[i][0]);
            
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //nums[j][i] -> nums[j/j-1/j+1][i-1]
                int temp2 = max((j-1 >= 0) ? nums[j-1][i-1] : 0,
                                (j+1 < m) ? nums[j+1][i-1] : 0);
                int temp1 = max(nums[j][i-1], temp2);
                
                nums[j][i] += temp1;
                    
                max_gold = max(max_gold, nums[j][i]);
            }
        }
        
        cout << max_gold << endl;
    }
}