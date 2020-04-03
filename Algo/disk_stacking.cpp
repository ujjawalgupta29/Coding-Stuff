#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef vector<int> VI;
typedef vector<vector<int>> VV;

struct parameters
{
    int width;
    int depth;
    int height;
};

bool compare(parameters p1, parameters p2)
{
    return p1.height < p2.height;
}

void build_sequence(vector<parameters> &info, VI &sequence, int max_idx)
{
    while(max_idx != -1)
    {
        cout << info[max_idx].width << " " << info[max_idx].depth << " " << info[max_idx].height << endl;
        max_idx = sequence[max_idx];
    }
}

void findMaxHeight(int disks, vector<parameters> &info)
{
    VI sequence(disks, -1);
    VI max_heights(disks, 0);
    sort(info.begin(), info.end(), compare);
    int max_idx = 0;

    ifor(i, 0, disks)
    {
        max_heights[i] = info[i].height;
        ifor(j, 0, i)
        {
            if(info[j].width < info[i].width && info[j].depth < info[i].depth && info[j].height < info[i].height)
            {
                if(max_heights[i] < info[i].height + max_heights[j])
                {
                    max_heights[i] = info[i].height + max_heights[j];
                    sequence[i] = j;
                }
            }
        }
        if(max_heights[max_idx] < max_heights[i])   max_idx = i;
    }

    build_sequence(info, sequence, max_idx);
}

int main()
{
    //Code
    int disks;
    cin >> disks;

    vector<parameters> info(disks);

    ifor(i, 0, disks) 
    {
        cin >> info[i].width;
        cin >> info[i].depth;
        cin >> info[i].height;
    }

    findMaxHeight(disks, info);
    return 0;
}

/*
6
2 1 2
3 2 3
2 2 8
2 3 4
1 3 1
4 4 5
*/