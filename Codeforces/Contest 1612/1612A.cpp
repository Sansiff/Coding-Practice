#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve(){
	int x, y; cin >> x >> y;
	if((x + y) & 1) cout << -1 << ' ' << -1;
	else if(x & 1) cout << (x >> 1) + 1 << ' ' << (y >> 1);
	else cout << (x >> 1) << ' ' << (y >> 1);
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