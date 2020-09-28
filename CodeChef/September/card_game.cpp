#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

unsigned long long power(unsigned long long x, 
                         int y, int p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCr(unsigned long long n, 
                                 int r, int p, unsigned long long fac[]) 
{ 
    // Base case 
    if (r == 0) 
        return 1;  
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> cards(n);
        int max_value = INT_MIN;
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++)
        {
            cin >> cards[i];
            freq[cards[i]]++;
            max_value = max(max_value, cards[i]);
        }

        int nums = n - freq[max_value];
        long long ans = power(2, nums, mod);

        int min_req = freq[max_value] / 2 + 1;
        long long total_comb = 0;

        // cout << "max freq = " << freq[max_value] << endl;
        // cout << "min_req = " << min_req << endl;
        unsigned long long fac[n + 1]; 
        fac[0] = 1; 
        for (int i = 1; i <= n; i++) 
            fac[i] = (fac[i - 1] * i) % mod; 

        for(int i=min_req; i<=freq[max_value]; i++)
        {
            // cout << "i= " << i << endl;
            long long combi = nCr(freq[max_value], i, mod, fac);
            // cout << " comb:- " << combi << endl;
            total_comb = (total_comb + combi) % mod; 
        }

        ans = (ans * total_comb) % mod;
        ans = (ans * 2) % mod;
        cout << ans << endl;
    }
    
}