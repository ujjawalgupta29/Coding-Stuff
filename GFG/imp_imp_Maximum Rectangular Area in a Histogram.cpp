#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
        }
        
        int max_area = INT_MIN;
        int area;
        
        stack<int> s;
        int i=0;
        while(i < n)
        {
            if(s.empty() || nums[i] >= nums[s.top()])
            {
                s.push(i++);
            }
            
            else
            {
                int top = s.top();
                top = nums[top];
                s.pop();
                
                if(s.empty())
                {
                    area = top * i;
                }
                else
                {
                    area = top * (i - s.top() - 1);
                }
                
                max_area = max(area, max_area);
            }
        }
        
        while(!s.empty())
        {
            int top = s.top();
            top = nums[top];
            s.pop();
            
            if(s.empty())
            {
                area = top * i;
            }
            else
            {
                area = top * (i - s.top() - 1);
            }
            
            max_area = max(area, max_area);
        }
        
        cout << max_area << endl;
    }
}