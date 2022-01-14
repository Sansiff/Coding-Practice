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
const int N = 150010,M = 2e5 + 10;
int a[N];
void solve() {
    int n; cin >> n;
    map<int,int> mp;
    int ans = -1;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(mp[a[i]]) ans = max(ans, mp[a[i]] + n - i);
        mp[a[i]] = i;
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