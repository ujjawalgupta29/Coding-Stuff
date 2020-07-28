#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string s;
        cin >> s;

        int len = s.size();
        int min_len = len;
        int idx1=0;
        int start,end;

        unordered_map<char, int> mp1;
        for(char ch : s)
            mp1[ch]++;

        unordered_map<char, int> mp2;
        int curr_chars=0;
        for(int i=0; i<len; i++)
        {
            mp2[s[i]]++;
            if(mp2[s[i]] == 1)
                curr_chars++;


            while(curr_chars == mp1.size())
            {
                if(min_len > i-idx1+1)
                {
                    min_len = min(min_len, i-idx1+1);
                    start = idx1;
                    end = i;
                }

                mp2[s[idx1]]--;
                if(mp2[s[idx1]] == 0)
                {
                    curr_chars--;
                }
                idx1++;
            }
        }

        cout << min_len << endl;
    }
}