// 


void solve(arr)
{
    int n = arr.size();
    int zero = 0, one = 0, two = n-1;

    // 0 0 1 1 2

    while(one < two)
    {
        if(arr[one] == 0)
        {
            swap(arr[zero], arr[one]);
            zero++;
            one++;
        }

        else if(arr[one] == 1)
        {
            one++;
        }
        // arr[one] == 2
        else
        {
            swap(arr[one], arr[two]);
            one++;
            two--;
        }
        
    }
}