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
        
        int col = n-1;
        int row = 0;
        
        for(int i=0; i<m; i++)
        {
            while(col >= 0 && nums[i][col] == 1)
            {
                col--;
                row = i;
            }
        }
        
        cout << row << endl;
    }
}