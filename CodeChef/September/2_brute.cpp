#include<bits/stdc++.h>
using namespace std;

bool checkSum(vector<int> &arr)
{
    int n = arr.size();

    int l=0, r=n-1;
    int sum_left = 0, sum_right = 0;

    while(l <= r)
    {
        if(sum_left < sum_right)
        {
            sum_left += arr[l++];
        }

        else
        {
            sum_right += arr[r--];
        }
        
    }

    if(sum_left == sum_right)
            return true;

    return false;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        int counts = 0;

        for(int i=0; i<n; i++)
            arr[i] = i+1;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(arr[i], arr[j]);
                if(checkSum(arr))
                {
                    // for(int x : arr)
                    // {
                    //     cout << x << " ";
                    // }
                    // cout <<endl;
                    counts++;
                }

                swap(arr[i], arr[j]);
            }
        }

        cout << counts << endl << endl;
    }
}