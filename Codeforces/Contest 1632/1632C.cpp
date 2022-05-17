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


void solve(){
    int a, b; cin >> a >> b;
    int res = b - a;
    for(int i = a; i <= b; i ++){
        res = min(res, i - a + (i | b) - b + 1);
    }
    for(int i = b; i <= 2 * b - a; i ++){
        if((i | a) == i) res = min(res, i - b + 1);
    }
    cout << res;
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