#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef unordered_map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;

VI findOrder(map<int, vector<int>> list, MI &job_degree)
{
    VI result;
    int jobs = job_degree.size();
    queue <int> q;

    for(auto it = job_degree.begin(); it != job_degree.end(); it++)
    {
        if(it->second == 0)
            q.push(it->first);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto it = list[node].begin(); it != list[node].end(); it++)
        {
            job_degree[*it]--;
            if(job_degree[*it] == 0)
                q.push(*it);
        }
    }

    return result;
}

int main()
{
    //Code
    int jobs;
    cin >> jobs;

    MI jobs_degree;

    ifor(i, 0, jobs) 
    {
        int temp;
        cin >> temp;
        jobs_degree[temp] = 0;
    }

    int num_dep;
    cin >> num_dep;

    VV dependencies(num_dep, VI(2));
    map<int, vector<int>> list;
    
    ifor(i, 0, num_dep)
    {
        cin >> dependencies[i][0] >> dependencies[i][1];
        jobs_degree[dependencies[i][1]]++;
        list[dependencies[i][0]].push_back(dependencies[i][1]);
    }

    VI result = findOrder(list, jobs_degree);

    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
/*
4
1
2
3
4
5
1 2
1 3
3 2
4 2
4 3
*/
//4 1 3 2 