#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tot, N, result1, K = 4;
pair < ll, ll > result1_pair;


void brute1(ll A, ll i){
	if (i == N + 1){
		if (abs( (tot -  A) - (A) ) < result1){
			result1_pair.second = A;
			result1 = abs((tot - A) - A);
		}
		return;
	}
	brute1(A + pow(i, K), i + 1);
	brute1(A, i + 1);
}


int main(){
	tot = 0;
	for (int i = 1; i <= 15; i ++){
		tot += i*i*i*i;
		result1 = 2e18;
		N = i;
		result1_pair = {-1,-1};
		brute1(0, 1);
		cout << result1 << ","; 			
	}	cout << "\n";
}