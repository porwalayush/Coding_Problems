//COPRIME SUBSEQUENCES
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mod 1000000007
 
const int N = 100005, M = 22;
 
int a[N], prime_count[N], mobius[N];
int freq[N], p2[N];
 
void cal_mobius() {
	int i, j;
	for (i = 1; i < N; i++) {
		a[i] = 1;
	}
	for (i = 2; i < N; i++) {
		if (prime_count[i]) continue;
		for (j = i; j < N; j += i) {
			prime_count[j]++;
			a[j] *= i;
		}
	}
	for (i = 1; i < N; i++) {
		if (a[i] == i) {
			// square free number
			if (prime_count[i] % 2 == 1) mobius[i] = -1;
			else mobius[i] = 1;
		}
		else {
			mobius[i] = 0;
		}
	}
}
 
void solve() {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cal_mobius();
	cin >> n;
	int b[n];
	for (i = 0; i < n; i++) {
		cin >> b[i];
		freq[b[i]]++;
	}
	p2[0] = 1;
	for (i = 1; i < N; i++) {
		p2[i] = p2[i - 1] * 2;
		p2[i] %= mod;
	}
	for (i = 1; i < N; i++) {
		cnt = 0;
		for (j = i; j < N; j += i) {
			cnt += freq[j];
		}
		// how many numbers are divisible by i
		int tot_subsequences = p2[cnt] - 1;
		ans += mobius[i] * tot_subsequences;
		ans %= mod;
	}
	ans += mod;
	cout << ans % mod;
}
 
void init() {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
	init();
	// int t;cin>>t;while(t--)
	{
		solve();
	}
}