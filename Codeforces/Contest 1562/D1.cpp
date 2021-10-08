
// 1562D1 Two Hundred Twenty One (easy version)
// data structures *1700

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
	 
void solve(){
	int n, m; cin >> n >> m;
	vector<int> res(n + 1), sum(n + 1), sum2(n + 1);
	for(int i = 1; i <= n; i ++){
		char c; cin >> c;
        if(c == '+') res[i] = 1;
        else res[i] = -1;
	}
    for(int i = 1; i <= n; i ++){
        if(i & 1) sum[i] = sum[i - 1] + res[i];
        else sum[i] = sum[i - 1] - res[i];
    }
    for(int i = 1; i <= m; i ++){
        int l, r; cin >> l >> r;
        int t = abs(sum[r] - sum[l - 1]);
        if(t == 0) cout << 0;
        else if(t & 1) cout << 1;
        else cout << 2;
        cout << endl;
    }
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t --){
		solve();
	}
	return 0;
}