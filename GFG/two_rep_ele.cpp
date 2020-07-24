#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
    }();
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> nums(n+2), counts(n+2, 0);
        
        for(int i=0; i<n+2; i++)
        {
            cin >> nums[i];
            
            counts[nums[i]]++;
            if(counts[nums[i]] == 2)
            {
                cout << nums[i] << " ";
            }
        }
        
        cout << endl;
    }
}