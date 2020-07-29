#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string s;
        cin >> s;
        
        if(s.size() % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }
        
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '}')
            {
                if(!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                
                else
                    st.push(s[i]);
            }
            
            else
                st.push(s[i]);
        }
        
        int len = st.size();
        int n = 0;
        
        while(!st.empty() && st.top() == '{')
        {
            n++;
            st.pop();
        }
        
        int m = len - n;
        
        if(m%2 != 0)    m++;
        if(n%2 != 0)    n++;
        
        cout << m/2 + n/2 << endl;
    }
}