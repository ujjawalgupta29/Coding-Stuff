#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int> &nums, vector<vector<int>> &res, int index)
{
    if(index == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for(int i=index; i<nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        permutations(nums, res, index+1);
        swap(nums[i], nums[index]);
    }

}

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    vector<vector<int>> res;

    permutations(nums, res, 0);

    cout<<"Permutations:-"<<endl;
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[0].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}