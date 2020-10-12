#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;

long long int expo(long long int x, unsigned long long int y, long long int p)  
{  
    long long int res = 1;   
  
    x = x % p; 
   
    if (x == 0)
        return 0;
  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}  

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long int a,b,n;
        cin >> a >> b >> n;

        n--;

        if(n%2 != 0)
        {
            long long int temp = (n - 1) / 2;
            long long int power = expo(2, temp, mod);
            // cout << power << endl;
            long long int num = a;
            a = (power * (b-a)) % mod;
            b = (power * ((b+num)%mod)) % mod;
        }

        else
        {
            long long int temp = (n) / 2;
            long long int power = expo(2, temp, mod);

            a = (power * a) % mod;
            b = (power * b) % mod;
        }

        cout << a << " " << b << endl;
        
    }
}