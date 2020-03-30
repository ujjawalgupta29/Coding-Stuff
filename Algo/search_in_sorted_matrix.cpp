//Time: - O(n+m)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin>> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i=0; i<m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    int target;
    cin>>target;

    vector<int> result(2);
    result[0] = result[1] = -1;

    int row = 0, col = matrix[0].size() - 1;

    while(row < matrix.size() && col >= 0)
    {
        if(matrix[row][col] > target)
            col--;

        else if(matrix[row][col] < target)
            row++;

        else
        {
            result[0] = row;
            result[1] = col;
            break;
        }
        
    }

    cout<<"Result:- "<<result[0]<<" "<<result[1]<<endl;
}