#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void insertAtBottom(int top, stack<int> &st)
{
        stack<int> temp;

        while(!st.empty())
        {
            int num = st.top();
            st.pop();
            temp.push(num);
        }

        temp.push(top);

        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
}

void reverse(stack<int> &st)
{
    if(st.empty())
        return;

    int top = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(top, st);
}

int main()
{
    int n;
    cin >> n;

    int x;
    stack<int> st;

    ifor(i, 0, n)
    {
        cin >> x;
        st.push(x);
    }

    reverse(st);

    while(!st.empty())
    {
        int top = st.top();
        cout << top << " ";
        st.pop();
    }
    
}