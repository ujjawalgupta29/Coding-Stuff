merege(arr[], int l int mid, int r)
{
    int temp[r-l+1];
    int leftidx = l;
    int rightIdx = mid+1;
    int tempIdx = l;
    while(leftIdx < mid && rightIdx < r )
    {
        if(arr[leftIdx] < arr[righIdx])
        {
            temp[]
        }
    }
}


void mergesort(int arr[], int l, int r)
{
    if(l < r)
    {
        mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}