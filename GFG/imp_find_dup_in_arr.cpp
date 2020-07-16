// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> duplicates(int a[], int n) {
    // code here
    vector<int> res;
    
    for(int i=0; i<n; i++)
    {
        int idx = a[i] % n;
        a[idx] += n;
    }
    
    for(int i=0; i<n; i++)
    {
        if(a[i]/n > 1)
        {
            res.push_back(i);
        }
    }
    
    if(res.size() == 0)
    {
        res.push_back(-1);
    }
    
    return res;
}
