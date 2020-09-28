#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int m, n;
        cin >> m >> n;

        vector<string> str(m);
        int sx, sy;

        for(int i=0; i<m; i++)
            cin >> str[i];

        int k;
        cin >> k;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                char ch = str[i][j];
                if(ch == 'M')
                {
                    sx = i;
                    sy = j;
                    str[i][j] = '.';
                    break;
                }
            }
        }


        queue<pair<int, pair<int, int>>> q;
        q.push({sx, {sy, 0}});
        bool flag = 1;
        vector<vector<int>> dir{
            {-1,0}, {1,0},
            {0,1}, {0,-1}
        };

        while(!q.empty())
        {
            auto top = q.front();
            q.pop();

            int x = top.first;
            int y = top.second.first;
            int checks = top.second.second;

            if(str[x][y] == '*')
            {
                // cout << "k = "  << k << endl;
                if(checks != k)
                {
                    flag = 0;
                }
                break;
            }

            str[x][y] = 'X';
            int counts = 0;

            for(int j=0; j<4; j++)
            {
                int xx = x + dir[j][0];
                int yy = y + dir[j][1];
                if(xx < 0 || yy < 0 || xx >= m || yy >= n || 
                    str[xx][yy] == 'X' || str[xx][yy] == 'M')
                    continue;
                counts++;
            }

            for(int i=0; i<4; i++)
            {
                int new_x = x + dir[i][0];
                int new_y = y + dir[i][1];

                if(new_x < 0 || new_y < 0 || new_x >= m || new_y >= n || 
                    str[new_x][new_y] == 'X')
                    continue;
                
                if(counts > 1)
                    q.push({new_x, {new_y, checks+1}});
                else
                    q.push({new_x, {new_y, checks}});
            }

            
        }
        if(flag)
            cout << "CORRECT" << endl;
        else
            cout << "NOT CORRECT" << endl;
    }
}
/*
.X.X......X
.X*.X.XXX.X
.XX.X.XM...
......XXXX.
*/

/*
.X.X......X
.X*.X.XXX.X
.XX.X.XM...
......XXXX.
*/