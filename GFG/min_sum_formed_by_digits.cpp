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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++)
        {
            cin >> nums[i];
            pq.push(nums[i]);
        }
        
        long num1=0, num2=0;
        int sz = pq.size();
        
        for(int i=0; i<sz; i++)
        {
            if(i%2 == 0)
            {
                num1 = num1*10 + pq.top();
                pq.pop();
            }
            
            else
            {
                num2 = num2*10 + pq.top();
                pq.pop();
            }
        }
        
        cout << num1+num2 << endl;
    }
}