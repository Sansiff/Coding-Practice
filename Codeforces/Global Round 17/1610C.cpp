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
	int n;  cin >> n;
	vector<PII> arr(n);
	for(int i=0;i < n; i ++){
		int a, b; cin >> a >> b;
		arr[i]={a,b};
	}
	int l = 1,r = n + 1;
	while(l < r - 1){
		int mid= (l + r) >> 1;
		int now = 0;
		for(int i = 0; i < n; i ++){
			if(arr[i].fi >= mid - now - 1 && arr[i].se >= now) ++now;
			if(now == mid) break;
		}
		if(now == mid) l=mid;
		else r = mid;
	}
	cout << l;
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