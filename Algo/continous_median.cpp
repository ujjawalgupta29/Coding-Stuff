#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;

void insert(int num, priority_queue<int> &lower_half, priority_queue<int, VI, greater<int> > &upper_half)
{
    if(lower_half.size() == 0 || lower_half.top() > num)
        lower_half.push(num);

    else
    {
        upper_half.push(num);
    }
    

    if(lower_half.size() - upper_half.size() == 2)
    {
        int temp = lower_half.top();
        lower_half.pop();
        upper_half.push(temp);
    }

    else if(upper_half.size() - lower_half.size() == 2)
    {
        int temp = upper_half.top();
        upper_half.pop();
        lower_half.push(temp);
    }
    
}

void getMedian(priority_queue<int> &lower_half, priority_queue<int, VI, greater<int> > &upper_half)
{
    if(lower_half.size() == upper_half.size())
        cout << (float)(lower_half.top() + upper_half.top()) / 2 << " ";

    else
    {
        if(lower_half.size() > upper_half.size())
            cout << lower_half.top();
        else
        {
            cout << upper_half.top();
        }
        cout<< " ";
    }
    
}

int main()
{
    //Code
    priority_queue<int> lower_half;
    priority_queue<int, VI, greater<int> > upper_half;

    insert(5, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    insert(10, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    insert(100, lower_half, upper_half); 
    getMedian(lower_half, upper_half);
    insert(200, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    insert(6, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    insert(13, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    insert(14, lower_half, upper_half);
    getMedian(lower_half, upper_half); 
    cout << endl;

    return 0;
}