#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef vector<int> VI;

int solve(vector< vector <int> > &knapsack, vector<int> &items, vector<int> &capacity, int item, int weight)
{
    for(int i=1; i<=item; i++)
    {
        for(int j=1; j<=weight; j++)
        {
            if(j < capacity[i-1])
                knapsack[i][j] = knapsack[i-1][j];

            else
            {
                knapsack[i][j] = max(knapsack[i-1][j], items[i-1] + knapsack[i-1][j-capacity[i-1]]);
            }
            
        }
    }

    return knapsack[item][weight];
}

VI getIndex(vector< vector <int> > &knapsack, vector<int> &capacity, int item, int weight)
{
    VI result;

    int i = item;
    int j = weight;

    while(i > 0)
    {
        if(knapsack[i][j] == knapsack[i-1][j])
            i--;

        else
        {
            result.push_back(i-1);
            j = j - capacity[i-1];
        }

        if(j == 0)
            break;
    }

    return result;
}

int main()
{
    //Code
    int item, weight;
    cin >> item >> weight;

    vector<int> items(item);
    vector<int> capacity(item);

    vector< vector <int> > knapsack(item + 1, vector<int>(weight + 1, 0));

    for(int i=0; i<item; i++)
    {
        cin >> items[i];
        cin >> capacity[i];
    }

    int max_value = solve(knapsack, items, capacity, item, weight);
    cout<< "Max Value" <<max_value<<endl;

    vector<int> indices = getIndex(knapsack, capacity, item, weight);
    cout<< "Indexes:- ";
    for(auto x : indices) cout << x << " ";

    cout<<endl;

    return 0;
}

/*
4 10
1 2
4 3
5 6
6 7
*/