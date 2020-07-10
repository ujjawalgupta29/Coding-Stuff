#include<bits/stdc++.h>
using namespace std;


int minmaxValue(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    priority_queue<vector<int>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    
    pq.push({A[0][0], 0, 0});
    visited[0][0] = 1;

    vector<int> dir = {-1, 0, 1, 0, -1};
    int res = A[0][0];

    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();

        res = min(res, temp[0]);

        if(temp[1] == m-1 && temp[2] == n-1)
        {
            return res;
        }

        for(int i=0; i<4; i++)
        {
            int x = temp[1] + dir[i];
            int y = temp[2] + dir[i+1];

            if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
                continue;

            visited[x][y] = 1;
            pq.push({A[x][y], x, y});
        }

    }

    return res;
}

int main()
{
    vector<vector<int>> A{
        {2,2,1,2,2,2},
        {1,2,2,2,1,2}
    };

    cout << minmaxValue(A);
    
}