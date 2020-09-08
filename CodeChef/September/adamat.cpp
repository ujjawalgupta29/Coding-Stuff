#include<bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &mat, int n)
{
    for(int i=0; i<n; i++)
    {
        swap(mat[0][i], mat[i][0]);
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

        vector<vector<int>> mat(n, vector<int>(n));
        vector<vector<int>> real(n, vector<int>(n));
        int number = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                real[i][j] = number;
                number++;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> mat[i][j];
            }
        }

        int counts = 0;

        for(int i=n-1; i>=1; i--)
        {
            if(mat[0][i] != real[0][i])
            {
                counts++;
                transpose(mat, i);
            }
        }

        cout << counts << endl;
    }
}