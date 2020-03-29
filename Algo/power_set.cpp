#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];

    int total_sets = pow(2, n);
    vector<vector<int>> powerSets(total_sets);
    
    for(int j=0; j<total_sets; j++)
    {
        for(int i=0; i<n; i++)
        {
            if( (j >> i) & 1)
            {
                powerSets[j].push_back(nums[i]);
            }
        }
    }

    cout<<"Power Sets:-"<<endl;
    for(int i=0; i<powerSets.size(); i++)
    {
        for(int j=0; j<powerSets[i].size(); j++)
        {
            cout<<powerSets[i][j]<<" ";
        }
        cout<<endl;
    }
}