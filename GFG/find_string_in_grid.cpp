#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(vector<vector<char>> &grid, 
            string word, int row, int col, int m, int n)
{
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    
    if (grid[row][col] != word[0]) 
        return false; 
  
    int len = word.length(); 
  
    for (int dir = 0; dir < 8; dir++) { 
        int k, rd = row + x[dir], cd = col + y[dir]; 
  
        for (k = 1; k < len; k++) { 
            if (rd >= m || rd < 0 || cd >= n || cd < 0) 
                break; 
  
            if (grid[rd][cd] != word[k]) 
                break; 
  
            rd += x[dir], cd += y[dir]; 
        } 
  
        if (k == len) 
            return true; 
    } 
    return false; 
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        
        vector<vector<char>> grid(m, vector<char>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                cin >> grid[i][j];
        }
        
        string word;
        cin >> word;
        bool flag = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(check(grid, word, i, j, m, n))
                {
                    flag = 1;
                    cout << i << " " << j << ", ";
                }
            }
        }
        
        if(flag == 0)
            cout << -1;
        
        cout << endl;
    }
}