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
        int len = s.size();
        
        stack<int> st;
        int max_len = 0;
        int curr_len = 0;
        
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            
            else
            {
                if(!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                }
                
                else 
                {
                    st.push(i);
                }
            }
            
        }
        
        unordered_map<int, int> idx;
        
        while(!st.empty())
        {
            idx[st.top()] = 1;
            st.pop();
        }
        
        int count=0;
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
            {
                count++;
                if(idx[i] == 1)
                {
                    curr_len = 0;
                }
            }
            
            else
            {
                if(idx[i] == 1)
                {
                    curr_len = 0;
                    continue;
                }
                
                count--;
                if(count >= 0)
                {
                    curr_len += 2;
                    max_len = max(max_len, curr_len);
                }
                else
                {
                    curr_len = 0;
                }
            }
        }
        
        cout << max_len << endl;
    }
}