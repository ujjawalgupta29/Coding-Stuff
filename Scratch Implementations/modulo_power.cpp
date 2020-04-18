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