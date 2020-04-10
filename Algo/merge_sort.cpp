#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

void merge(VI &nums, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    VI left(nums.begin() + l, nums.begin() + mid + 1);
    VI right(nums.begin() + mid + 1, nums.begin() + r + 1);

    int k = l;
    int i = 0, j = 0;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }
        k++;
        
    }

    while(i < n1)
    {
        nums[k] = left[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        nums[k] = right[j];
        j++;
        k++;
    }


}

void merge_sort(VI &nums, int l, int r)
{
    if( l < r)
    {
        int mid = l + (r - l) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
}

int main()
{
    //Code
    int n;
    cin >> n;

    vector<int> nums(n);
    ifor(i, 0, n)   cin >> nums[i];

    merge_sort(nums, 0, n-1);

    for(int x : nums)   cout << x << " ";
    cout << endl;

    return 0;
}