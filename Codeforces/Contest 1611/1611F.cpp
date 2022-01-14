#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve() {
	int n,s; cin >> n >> s;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0, al, ar;
	for(int l = 1, r = 1, now = s; r <= n; r ++){
		now += a[r];
		while(now<0) now-=a[l],++l;
		if(r - l + 1 > ans) ans = r - l + 1, al = l, ar = r;
	}
	if(!ans) cout << -1;
	else cout << al << ' ' << ar;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}