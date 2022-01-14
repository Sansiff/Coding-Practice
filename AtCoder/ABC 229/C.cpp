#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define rep(i, l, r) for(int i = l; i < r; i ++)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res *= a, b --;
        else a *= a, b /= 2;
    }
    return res;
}

const int N = 3e5  + 10;
PII a[N];
inline void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(m > a[i].se) {
            ans += 1LL * a[i].fi * a[i].se;
            m -= a[i].se;
        } else {
            ans += 1LL * a[i].fi * m;
            break;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}