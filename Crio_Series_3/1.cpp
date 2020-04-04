#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;

long long reverse(long long num)
{
    long long res = 0;

    while(num > 0)
    {
        int temp = num % 10;
        res = res*10 + temp;
        num /= 10;
    }

    return res;
}

int main()
{
    //Code
    long long x, y;
    cin >> x >> y;
    int min_ops = -1;
    
    set <int> values_visited;
    queue<pair<int, int>> nums;
    
    nums.push(make_pair(x, 0));
        
    while(!nums.empty())
    {
        int temp_num = nums.front().first;
        int temp_ops = nums.front().second;
        nums.pop();

        if(temp_num == y)
        {
            min_ops = temp_ops;
            break;
        }
        values_visited.insert(temp_num);

        if(values_visited.find(temp_num/10) == values_visited.end())
        {
            nums.push(make_pair(temp_num/10, temp_ops+1));
        }

        int rev_num = reverse(temp_num);
        if(values_visited.find(rev_num) == values_visited.end())
        {
            nums.push(make_pair(rev_num, temp_ops+1));
        }

    }
    
    cout << min_ops << endl;

    return 0;
}