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
void read(VI& a){
    for(int& x : a) cin >> x;
}
void solve() {
    int n; cin >> n;
    VI a(n); read(a);
    int ans = a.back();
    int idx = 0, cnt = 0;
    reverse(all(a));
    rep(i, 0, n) {
        while(idx < n - 1 && a[idx + 1] == ans) idx ++;
        if(idx == n - 1) break;
        cnt ++, idx = 2 * idx + 1;
        if(idx >= n - 1) break;
    }
    cout << cnt;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << '\n';
    }
    return 0;
}