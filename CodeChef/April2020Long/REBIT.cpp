#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
ll mod = 998244353;
ll num_of_hash = 0;

ll power(ll a , ll n)
{
	ll res = 1;
	
	while(n)
	{
		if(n & 1)
			res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}

ll add(ll res, ll to_add)
{
    return (res + to_add) % mod;
}

VL  apply(VL a, VL b, char curr_op)
{
    VL res(4, 0);

    if(curr_op == '&')
    {
        res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[0] = add(res[0] , (a[1] * b[0]) % mod);
		res[0] = add(res[0] , (a[2] * b[0]) % mod);
		res[0] = add(res[0] , (a[3] * b[0]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[2] = add(res[2] , (a[2] * b[1]) % mod);
		res[3] = add(res[3] , (a[3] * b[1]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[2]) % mod);
		res[2] = add(res[2] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[0] = add(res[0] , (a[3] * b[2]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[3]) % mod);
		res[3] = add(res[3] , (a[1] * b[3]) % mod);
		res[0] = add(res[0] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
    }

    else if(curr_op == '|')
    {
        res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[1] = add(res[1] , (a[2] * b[1]) % mod);
		res[1] = add(res[1] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[1] = add(res[1] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[1] = add(res[1] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
    }

    else
    {
        res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[0] = add(res[0] , (a[1] * b[1]) % mod);
		res[3] = add(res[3] , (a[2] * b[1]) % mod);
		res[2] = add(res[2] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[3] = add(res[3] , (a[1] * b[2]) % mod);
		res[0] = add(res[0] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[2] = add(res[2] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[0] = add(res[0] , (a[3] * b[3]) % mod);
    }

    return res;
    
}

VL getResult(string exp)
{
    ll n = exp.size();
    stack<char> op;
    stack<char> paran;
    stack<VL> num;
    VL hash{1,1,1,1};

    for(char ch : exp)
    {
        if(ch == '(')
            paran.push('(');
        else if(ch == '&' || ch == '|' || ch == '^')
            op.push(ch);
        else if(ch == '#')
        {
            num.push(hash);
            num_of_hash++;
        }
        else
        {
            paran.pop();
            
            VL a = num.top();
            num.pop();

            VL b = num.top();
            num.pop();

            char curr_op = op.top();
            op.pop();

            num.push(apply(a, b, curr_op));
        }
        
    }

    return num.top();
}


int main()
{
    //Code
    int t;
    cin >> t;

    while(t--)
    {
        string exp;
        cin >> exp;

        num_of_hash = 0;
        VL res = getResult(exp);
        ll denom = power(power(4,num_of_hash), mod - 2);

        cout << (res[0] * denom) % mod << " ";
        cout << (res[1] * denom) % mod << " ";
        cout << (res[2] * denom) % mod << " ";
        cout << (res[3] * denom) % mod << endl;
    }
    return 0;
}