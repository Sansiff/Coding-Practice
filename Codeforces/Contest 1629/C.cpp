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
typedef vector<vector<int>> VII;
typedef vector<PII> VPII;
constexpr int N = 1e6 + 10;
int sum[N], f[N], res[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n + 1) sum[i] = f[i] = 0;
    for(int &x: a) cin >> x, sum[x] ++;
    int idx = 0;
    int px = 0, prer = 0;
    for(int i = 1; i <= n; i ++ ) {
        f[a[i - 1]] ++;
        while(f[px]) ++ px;
        if(!sum[px]) {
            res[++ idx] = px;
            for(int j = prer + 1; j <= i; j ++ )
                f[a[j - 1]] = 0, sum[a[j - 1]] --;
            prer = i, px = 0;
        }
    }
    cout << idx << endl;
    rep(i, 1, idx + 1) cout << res[i] << ' ';
}
 
signed main() {
    int _; cin >> _; 
    while(_ -- ) {
        solve();
        cout << '\n';
    }
    return 0;
}
