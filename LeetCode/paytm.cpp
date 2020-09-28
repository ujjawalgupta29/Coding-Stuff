int minJumps(arr)
{
    int len = arr.size();
    int jump = arr[0];

    if(jump == 0)
        return -1;

    int idx = 1;
    int counts = 1;

    int max_jumps = INT_MIN;
    int max_idx = -1;

    while(jumps-- && idx < n)
    {
        if(max_jumps < idx + arr[idx])
        {
            max_jumps = idx + arr[idx];
            max_idx = idx;
        }

        if(jumps == 0)
        {
            jumps = arr[max_idx] - (idx - max_idx);
            counts++;
        }

        idx++;
    }
    if(idx == n-1)
        return counts;

    return -1;
}