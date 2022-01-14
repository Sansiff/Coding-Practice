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
    int n, k; cin >> n >> k;
    vector<int> a(n); read(a);
    vector<int> cnt(k);
    for(int i = 0; i < n; i ++ ) {
        int x = a[i];
        for(int j = 0; j < k; j ++ ) {
            if(x & 1) cnt[j] ++;
            x >>= 1;
        }
    }
    int ans = 0;
    for(int i = k - 1; i >= 0; i -- ) {
        ans <<= 1;
        int x = cnt[i], y = n - cnt[i];
        if(x > y) ans ++;
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
    return 0;
}